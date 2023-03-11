// filesize.c: Lession 5 - examples
//
// cl /Od /Zi filesize.c
// gcc -O2 filesize.c -o filesize
//
// -or- make TARGET=filesize
//
// Example: Two ways of obtaining the size of a file in bytes.
//          Works equally werll with binary as with text files.

#include <stdio.h>
#include <sys/stat.h>

void main (void)
{
   long lSize = 0;
   FILE *f;

   // File size of an open file:

   f = fopen ("adventures.txt", "r");
   if (f != NULL) {
      if (fseek(f, 0, SEEK_END) == 0) {
         lSize = ftell(f);
         printf ("Size of file: %ld\n", lSize);
         rewind(f);
      }
      fclose (f);
   }

   // Another way, without opening the file:

   struct stat sBuffer;
   int iRc;

   iRc = stat("adventures.txt", &sBuffer);
   if (iRc == 0) {
     printf ("Size of file: %ld\n", sBuffer.st_size);
   }
}
