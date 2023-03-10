// ex4.c: Lession 3, exercise 4:
//
// cl /Od /Zi ex4.c
// gcc -O2 ex4.c -o ex4
//
// -or- make TARGET=ex4
//

#include <stdio.h>

void main (void)
{
   int iBottles;

   for (iBottles = 99; iBottles > 0; iBottles--) {
      printf ("%d bottles of beer on the wall, %d bottles of beer.\n", iBottles, iBottles);
      if (iBottles > 1) {
         printf ("Take one down and pass it around, %d bottles of beer on the wall.\n", iBottles - 1);
      }
      else {
         printf ("Take one down and pass it around, no more bottles of beer.\n");
      }
   }
   printf ("No more bottles of beer on the wall, no more bottles of beer.\n"
           "We've taken them down and passed them around; now we're drunk and passed out!\n");

}
