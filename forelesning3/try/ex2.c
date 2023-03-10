#include <stdio.h>

void main (void) {

	int a, b, c, d;
	int x, y, z, w;
	
	a = 5;
	b = a++; // a++ and ++a will change the value of A to 6 no matter what 
	c = ++b; //b value is 5 but ++b made it 6 thus d = 7
	d = ++c;
	
	//a++ means value first ++a value after 
	
	printf("a = %d, b = %d, c = %d, d = %d \n", a, b, c, d);
	printf("a = %d \n", a);

	x = 10;
	y = 9;
	z = 8;
	w = 7;
	b = ++y;
	
	if ((x == y++) && (z == ++x)){ //this if statement adds 1 to value of y
		w = 100;
		printf("This is true.\n");
	}
	else if (w == y++){
		printf("Nice.\n");
	}
	
	
	z = ++w + y++; // ++ is adding 1 to W and Y. Thus z = 18 and y is 11
	printf("x = %d y = %d z = %d w = %d\n", x, y, z, w);
}


