// readbinary.c: Lession 5 - examples
//
// cl /Od /Zi readbinary.c
// gcc -O2 readbinary.c -o readbinary
//
// -or- make TARGET=readbinary
//
// Example: Read doubles from the binary file produced by
//          "writebinary" and print them to the screen:
//

#include <stdio.h>
#include <sys/stat.h>

void main (void)
{
   FILE *f;
   double lfNum = 0.0;

   f = fopen ("doubles.dat", "rb");
   if (f != NULL) {
      while (!feof(f)) {
         if (fread (&lfNum, sizeof(double), 1, f) == 1) {
            printf ("%lf\n", lfNum);
         }
      }
      fclose (f);
   }
}

// How to get the data read onto a text file?
//
// Use redirection as "writebinary > textfile.txt"
// or see bintotxt.c

