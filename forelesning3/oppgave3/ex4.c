#include <stdio.h>

int main (void)
{
	int iBottles; 
	
	for (iBottles = 99; iBottles > 0; iBottles--){
	printf("%d bottles of beer on the wall, %d bottles of beer.\n", iBottles, iBottles);
		if (iBottles > 1){
		printf("Take one down and pass it around, %d bottles of beer.\n", iBottles, iBottles);
		}
		else {
	printf("Take one down and pass it around, no more bottles of beer.\n");
		}
	}
	printf("No more bottles of beer on the wall, no more bottles of beer.\n" "We've taken them down and passed them around; now we're drunk and passed out!\n");
	
}

