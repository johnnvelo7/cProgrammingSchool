#include <stdio.h>

int a, b;

void main (void)
{
   int i, j;
   printf("Addresses of global variables: %p %p\n", &a, &b);
   printf("Addresses of local variables: %p %p\n", &i, &j);
}

