// ex3.c: Lession 7, exercise 4
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "list.h"

#define TESTFIL "testfile.txt"

// #define SAFE_PARSING

#ifdef SAFE_PARSING
static int SafeParseFile (LIST **ppHead, char *pszFileName);
static long GetLineLength (FILE *f);
#define Parse SafeParseFile
#else
static int UnsafeParseFile (LIST **ppHead, char *pszFileName);
#define Parse UnsafeParseFile
#endif
static int PrintValue (LIST *pHead, const char *pszKey);

int main (void)
{
   LIST *pHead = NULL;
   int iRc = OK;

   printf ("\nInserting values:\n");

   iRc = Parse (&pHead, TESTFIL);
   if (iRc != OK) {
      printf ("Could not parse file %s.\n", TESTFIL);
      return 1;
   }

   Dumplist (pHead);

   printf ("\nLooking up values:\n");
   PrintValue (pHead, "college");
   PrintValue (pHead, "rev");
   PrintValue (pHead, "students");

   char *pszKey = "college";
   printf ("\nAttempting to delete '%s'\n", pszKey);
   iRc = Delete (&pHead, pszKey);
   if (iRc == OK) {
      printf ("Deleted '%s' Ok.\n", pszKey);
   }
   else {
      printf ("Could not delete '%s'.\n", pszKey);
   }

   Dumplist (pHead);
}

static int PrintValue (LIST *pHead, const char *pszKey)
{
   char *pszValue = NULL;
   int iValue = 0;

   int iRc = Lookup (pHead, pszKey, &pszValue, &iValue);
   if (iRc == OK) {
      if (pszValue) {
         printf ("%s = '%s'\n", pszKey, pszValue);
      }
      else {
         printf ("%s = %d\n", pszKey, iValue);
      }
   }
   else {
      printf ("%s cannot be found.\n", pszKey);
   }
   return iRc;
}

#ifndef SAFE_PARSING

// This way of doing it is a bit unsafe. Why so?
// See also the outcommented SafeParseFile() below.

static int UnsafeParseFile (LIST **ppHead, char *pszFileName)
{
   FILE *f;
   char szKey[32];
   char szValue[80];
   int iValue = 0;
   char *pc = NULL, *pcb = NULL;
   int iRc = OK;
   int iLine = 1;

   f = fopen (pszFileName, "r");
   if (f == NULL) {
      printf ("Cannot open %s.\n", pszFileName);
      return ERROR;
   }

   while (!feof(f) && (iRc == OK)) {
      if (fscanf (f, " %[^=] = %[^\n]\n", szKey, szValue) == 2) {
         pc = strchr(szKey, ' ');           // Look for ending space.
         if (pc) *pc = '\0';                // Terminate key.
         iValue = 0;
         pc = strchr (szValue, '"');        // Look for quotes.
         if (pc) {                          // Got it.
            ++pc;                           // Skip it.
            pcb = strchr (pc, '"');         // Look for end-quote
            if (pcb) {                      // We got it.
               *pcb = 0;                    // Cut off string at quote.
            }
            else {
               printf ("Missing quote in line %d.\n", iLine);
               iRc = ERROR;
            }
         }
         else {
            if (sscanf(szValue, "%d", &iValue) != 1) {
               printf ("No numeric value as expected in line %ds.\n", iLine);
               iRc = ERROR;
            }
         }
         if (iRc == OK) {
            // At this point we should have an szKey, pc == string value or iValue:
            printf ("Ready to insert %s = '%s' or %d\n", szKey, pc, iValue);
            iRc = InsertSorted (ppHead, szKey, pc, iValue);
            if (iRc != OK) {
               printf ("Insert in list failed in line %d.\n", iLine);
            }
         }
      }
      else {
         printf ("Syntax error in line %d.\n", iLine);
         iRc = ERROR;
      }
      ++iLine; // Count lines.
   }
   fclose (f);
   return iRc;
}

#else // def SAFE_PARSING

static int SafeParseFile (LIST **ppHead, char *pszFileName)
{
   FILE *f;
   char szKey[32];
   char *pszValue = NULL;
   int iValue = 0;
   char *pszLine = NULL, *pc = NULL, *pck = NULL;
   int iRc = OK;

   f = fopen (pszFileName, "r");
   if (f == NULL) {
      printf ("Cannot open %s.\n", pszFileName);
      return ERROR;
   }

   while (!feof(f) && (iRc == OK)) {
      long lLen = GetLineLength(f);           // Get line length.
      pszLine = malloc (lLen);                // Allocate buffer of correct length.
      if (pszLine) {
         if (fscanf(f, "%[^\n]\n", pszLine) == 1) {  // fscan "eats" the line ending.
            // We got the line, including the '\n'
            pck = pszLine;
            pszValue = NULL;
            iValue = 0;
            while (isspace(*pck)) ++pck;      // Skip leading white space.
            pc = strchr (pck, '=');           // Look for a '=' ...
            if (pc) {                         // We got it.
               if (isspace(*(pc - 1))) {
                  pc--;
                  while (isspace(*pc)) pc--;  // Skip spaces before '='
                  pc++;
               }
               int iLen = pc - pck;           // Length of keyword ...
               if (iLen < sizeof(szKey)) {    // Ok length?
                  strncpy (szKey, pck, iLen); // Yep. Copy keyword.
                  szKey[iLen] = '\0';         // Add 0-termination.
                  pc = strchr (pc, '=');      // Find the '=' again...
                  ++pc;                       // Skip it.
                  while (isspace(*pc)) ++pc;  // Skip spaces after '='
                  if (*pc == '"') {           // Do we have a quote ?
                     pck = ++pc;              // Skip it and save pointer.
                     pc = strchr(pck, '"');   // Do we have another quote ?
                     if (pc) {
                        *pc = 0;              // Terminate string
                        pszValue = pck;       // Save pointer to string value.
                     }
                     else {
                        printf ("Missing end quote in %s.\n", pszLine);
                        iRc = ERROR;
                     }
                  }
                  else {                      // We didn't have a quote.
                     if (sscanf(pc, "%d", &iValue) != 1) {
                        printf ("No numeric value as expected in %s.\n", pszLine);
                        iRc = ERROR;
                     }
                  }
                  if (iRc == OK) {
                     // At this point we should have an szKey, pszValue or iValue:
                     printf ("Ready to insert %s = '%s' or %d\n", szKey, pszValue, iValue);
                     iRc = InsertSorted (ppHead, szKey, pszValue, iValue);
                     if (iRc != OK) {
                        printf ("Insert in list failed for %s.\n", pszLine);
                     }
                  }
               }
               else {
                  printf ("Keyword too long in %s.\n", pszLine);
                  iRc = ERROR;
               }
            }
            else {
               printf ("Syntax error in %s.\n", pszLine);
               iRc = ERROR;
            }
         }
         else {
            printf ("Could not read from file.\n");
            iRc = ERROR;
         }
         free (pszLine);
         pszLine = NULL;
      }
      else {
         printf ("malloc failed.\n");
         iRc = ERROR;
      }
   }
   fclose(f);
   return iRc;
}

// Not optimal, but safe:

static long GetLineLength (FILE *f)
{
   char c;
   long l = 0;

   long lPos = ftell(f);
   while (!feof(f)) {
      c = fgetc(f);
      ++l;
      if (c == '\n') break;
   }
   fseek(f, lPos, SEEK_SET); // Set file pos bak to start of line.
   return l;
}

#endif // def SAFE_PARSING
