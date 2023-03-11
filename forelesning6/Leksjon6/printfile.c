// printfile.c: Lession 5 - examples
//
// cl /Od /Zi printfile.c
// gcc -O2 printfile.c -o printfile
//
// -or- make TARGET=printfile
//
// Example: Read a text file, line-by-line
//          and prints it on the screen.
//

#include <stdio.h>
#include <stdlib.h>

int main (int iArgC, char *apszArgV[])
{
   FILE *f = NULL;
   char szLine [160];      // Assume max line length
   int iLine = 0;

   if (iArgC < 2) {
      printf ("Usage: printfile <file name>\n");
      return 1;
   }

   f = fopen (apszArgV[1], "r"); // Text read.
   if (f != NULL) {
      while (!feof(f)) {
         if (fgets (szLine, sizeof(szLine), f)) {
            printf ("%3d: %s", ++iLine, szLine);
         }
      }
      fclose (f);
   }
}


