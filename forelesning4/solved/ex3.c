// ex1.c: Lession 4, exercise 3:
//
// cl /Od /Zi ex3.c
// gcc -O2 ex3.c -o ex3
//
// -or- make TARGET=ex3
//

#include <stdio.h>

void main (void)
{
   int a,b;

   printf("Type two integers seperated with space\n");
   scanf("%d %d", &a, &b);
   printf("The numbers are %d, %d \n", a, b);

   // Using pointers in scanf():

   int *pa, *pb;
   pa = &a;
   pb = &b;

   printf("Type two integers seperated with space\n");
   scanf("%d %d", pa, pb);
   printf("The numbers are %d, %d \n", *pa, *pb);
   printf("Another way to print the same numbers %d, %d :-) \n", a, b);
}
