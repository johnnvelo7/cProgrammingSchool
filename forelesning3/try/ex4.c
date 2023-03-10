#include <stdio.h>

void main (void) {

	int iBottles;
	
	//For loop
	for (iBottles = 99; iBottles > 0; iBottles--){ //99 to 0 and -- decrement
		printf("%d bottles of beer on the wall, %d bottles of beer.\n", iBottles, iBottles); //Because number of bottles and beers are same
		
		if(iBottles > 1){ //as long as its greater , print and minus the bottle
			printf("Take one down and pass it around, %d bottles of beer on the wall.\n", iBottles - 1);
		}
		else { //is it is less than then it is 0
			printf("Take one down and pass it around, no more bottles of beer.\n");
		}
	} //just a final print
	printf("No more bottles of beer on the wall, no more bottles of beer.\n"
           "We've taken them down and passed them around; now we're drunk and passed out!\n");
}
