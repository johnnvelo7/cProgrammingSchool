// bintotxt.c: Lession 5 - examples
//
// cl /Od /Zi bintotxt.c
// gcc -O2 bintotxt.c -o bintotxt
//
// -or- make TARGET=bintotxt
//
// Example: Read doubles from the binary file produced by
//          "writebinary" and prints them to a text file.
//

#include <stdio.h>

void main (void)
{
   FILE *fb, *ft;
   double lfNum = 0.0;

   fb = fopen ("doubles.dat", "rb");
   if (fb != NULL) {
      ft = fopen ("doublesastext.txt", "w");
      if (ft != NULL) {
         while (!feof(fb)) {
            if (fread (&lfNum, sizeof(double), 1, fb) == 1) {
               fprintf (ft, "%lf\n", lfNum);
            }
         }
         fclose (ft);
      }
      fclose (fb);
   }
}

