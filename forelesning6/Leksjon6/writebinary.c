// writebinary.c: Lession 5 - examples
//
// cl /Od /Zi writebinary.c
// gcc -O2 writebinary.c -o writebinary
//
// -or- make TARGET=writebinary
//
// Example: Write 100 doubles to a binary file.
//

#include <stdio.h>

void main (void)
{
   FILE *f;

   f = fopen ("doubles.dat", "wb");
   if (f != NULL) {
      for (int i = 0; i < 100; i++) {
         double lfNum = (double) i;
         fwrite (&lfNum, sizeof(double), 1, f);
      }
      fclose (f);
   }
}
