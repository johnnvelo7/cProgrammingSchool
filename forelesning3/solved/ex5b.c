// ex5a.c: Lession 3, exercise 1:
//
// cl /Od /Zi ex5a.c
// gcc -O2 ex5a.c -o ex5a
//
// -or- make TARGET=ex5a
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main (void)
{
   srand (time(NULL));
   int a = rand() % 40;
   int aSaved = a;

   int sum = 0;
   while (a > 0){
      sum = sum + a--;
   }
   printf("Sum is %d.\n", sum);

   // ----------
   for (int i = 0, sum = 0; i < aSaved; sum += i, i++);
   printf("Sum is %d.\n", sum);

   // ----------
   for (a = aSaved, sum = 0; a > 0; sum += a, a--);
   printf("Sum is %d.\n", sum);

   // ----------
   sum = 0;
   for (int i = 0; i <= aSaved; i++) {
      sum += i;
   }
   printf("Sum is %d.\n", sum);

   // ----------
   sum = 0;
   a = aSaved;
   do {
      sum += a;
   } while (--a > 0);
   printf("Sum is %d.\n", sum);

}


