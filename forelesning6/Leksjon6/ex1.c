#include <stdio.h>
#include <stdlib.h>

//We need to define maximum number of doubles in file
#define MAX_NUMS 1000

int main (int argc, char *argsv[]){
	FILE *fpointer, *fpointerBinary, *fpointerText;
	double nums[MAX_NUMS];
	int count = 0; 

	//Here is to open the text file for ONLY READING 
	fpointer = fopen("numbers.txt", "r"); //numbers.txt is the name of the file
	if (fpointer == NULL){
		printf("Error opening the file\n");
		return 1; //1 for error
	}
	
	//Here is to read the double numbers from the text file 
	while (fscanf(fpointer, "%lf", &nums[count]) == 1){
		count++;
	}
	fclose(fpointer);
	
	//Open the binary file for writing
	fpointerBinary = fopen("output.bin", "wb");
	if (fpointerBinary == NULL){
		printf("Error opening file\n");
		return 1;
	}
	
	//Write the double to the binary file
	fwrite(nums, sizeof(double), count, fpointerBinary);
	fclose(fpointerBinary);
	
	//Open the text file for writing
	fpointerText = fopen("number_new.txt", "w");
	if (fpointerText == NULL){
		printf("Error opening file\n");
		return 1;
	}
	
	//Open the binary file for reading
	fpointerBinary = fopen("output.bin", "rb");
	if (fpointerBinary == NULL){
		printf("Error opening file\n");
		return 1;
	}
	
	//Read the doubles from the binary file and write them to the text file
	while (fread(&nums[count], sizeof(double), 1, fpointerBinary) == 1)	{
		fprintf(fpointerText, "%.15g\n", nums[count]);
		count++;
	}
	fclose(fpointerBinary);
	fclose(fpointerText);

	return 0;
}
