// ex2.c: Lession 3, exercise 2:
//
// cl /Od /Zi ex2.c
// gcc -O2 ex2.c -o ex2
//
// -or- make TARGET=ex2
//

#include <stdio.h>

void main (void)
{
   int a, b, c, d;
   int x, y, z, w;

   a = 5;
   b = a++;
   c = ++b;
   d = b++;

   printf ("a=%d b=%d c=%d d=%d\n", a, b, c, d);

   x = 10;
   y = 9;
   z = 8;
   w = 7;
   b = ++y;

   if ((x == y++) && (z == ++x)) {
      w = 100;
      printf("This is obviously true.\n");
   }
   z = ++w + y++;

   printf ("x=%d y=%d z=%d w=%d\n", x, y, z, w);

}


	
	
