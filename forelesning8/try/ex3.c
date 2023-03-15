#include <stdio.h>
#include <stdlib.h>

/* 

A ring buffer is something of a queue that has the front and back connected.
Write a function that lets you initialize a ring buffer with binary elements
and that has the following operations. You can assume that the buffer has 8
elements exactly

-shift left by n units-
-shift right by n units-


*/

typedef unsigned char BYTE;

void PrintBinary(BYTE byteNum);
int RotateLeft (BYTE *pbyteRing, int intBits);
int RotateRight (BYTE *pbyteRing, int intBits);

int main (int iArgC, char *apszArgV[]){

	BYTE byteRing;
	byteRing = 0x42;
	PrintBinary(byteRing);
	
	RotateLeft (&byteRing, 2);
	PrintBinary(byteRing);
	
	RotateRight (&byteRing, 2);
	PrintBinary(byteRing);
	
	RotateRight (&byteRing, 3);
	PrintBinary(byteRing);
	
	RotateLeft (&byteRing, 3);
	PrintBinary(byteRing);

	return 0;
}

void PrintBinary(BYTE byteNum){

	for (int i = 0; i < 8; i++){
		printf("%c", ((byteNum & 0x80) >> 7) + '0');
		byteNum <<= 1;
	}
	printf("\n");
}


int RotateLeft (BYTE *pbyteRing, int intBits){

	BYTE byteCarry;
	BYTE byteMask;
	
	byteMask = 0xFF << (8 - intBits); //Makes the mask
	byteCarry = (*pbyteRing & byteMask);
	byteCarry >>= (8 - intBits);
	*pbyteRing <<= intBits;
	*pbyteRing |= byteCarry;

}
int RotateRight (BYTE *pbyteRing, int intBits){

	BYTE byteCarry;
	BYTE byteMask;
	
	byteMask = 0xFF >> (8 - intBits); //Makes Mask
	byteCarry = (*pbyteRing & byteMask);
	byteCarry <<= (8 - intBits);
	*pbyteRing >>= intBits;
	*pbyteRing |= byteCarry;
}
