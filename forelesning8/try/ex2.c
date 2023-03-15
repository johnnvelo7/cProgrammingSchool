#include <stdio.h>
#include <stdarg.h>

/*

Write a function that prints 8-bit unsigned integer as a binary output.
write a function that inverts the bits in a character and print out the character.

*/

typedef unsigned char BYTE;

void PrintBinary(BYTE byteNum){

   for (int i = 0; i < 8; i++) { // 8 bits 
      printf ("%c", ((byteNum & 0x80) >> 7) + '0'); // 7 = 8 cuz array ?
      byteNum <<= 1;
      // if (!((i + 1) % 4)) printf (" "); (This is not on the code)
   }
   printf ("\n");
}

int main(int iArgC, char *apszArgV[]){

   PrintBinary(0xFF); // 1111
   PrintBinary(0x10);
   PrintBinary(1);
   PrintBinary(-1);
   PrintBinary(255);
}
