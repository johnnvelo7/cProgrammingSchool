// ex1.c: Lession 4, exercise 1:
//
// cl /Od /Zi ex1.c
// gcc -O2 ex1.c -o ex1
//
// -or- make TARGET=ex1
//

#include <stdio.h>

int a, b;

void main (void)
{
   int i, j;
   printf("Addresses of global variables: %p %p\n", &a, &b);
   printf("Addresses of local variables: %p %p\n", &i, &j);
}
