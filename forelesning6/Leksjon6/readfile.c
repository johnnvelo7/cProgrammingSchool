// readfile.c: Lession 5 - examples
//
// cl /Od /Zi readfile.c
// gcc -O2 readfile.c -o readfile
//
// -or- make TARGET=readfile
//
// Example: Finds the size of a file, creates a buffer
//          then reads the file in one chunk.
//
//          For reading a file in chunks, see Md5/print_md5.c
//

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;  // Nice to have

int main (int iArgC, char *apszArgV[])
{
   FILE *f = NULL;
   BYTE *byBuffer = NULL;
   long lSize = 0, lBytesRead;

   if (iArgC < 2) {
      printf ("Usage: readfile <file name>\n");
      return 1;
   }

   f = fopen (apszArgV[1], "rb"); // Binary read. "r" for text would work too.
   if (f != NULL) {
      if (fseek(f, 0, SEEK_END) == 0) {
         lSize = ftell(f);
         printf ("Size of file is %ld bytes.\n", lSize);
         rewind(f);

         byBuffer = malloc (lSize);
         if (byBuffer != NULL) {
            lBytesRead = fread (byBuffer, sizeof(BYTE), lSize, f);
            if (lBytesRead == lSize) {
               // We got it all:
               printf ("%ld bytes read.\n", lBytesRead);
            }
            free (byBuffer);
         }
      }
      fclose (f);
   }
}


