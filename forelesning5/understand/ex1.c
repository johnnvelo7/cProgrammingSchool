#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void BubbleSort(int *row, int cols);


//Main program 
int main (int argc, char *argsv[]){

	//Variables
	int rows, cols, i, j, k, num, random_row, sort_row;
	int *prows, *pcols;
	prows = &rows;
	pcols = &cols;
	
	//Print the things and asks the user for array size
	printf("Please enter the number of rows: ");
	scanf("%d", prows); //This can be a pointer for value of rows 
	
	printf("Please enter the number of columns: ");
	scanf("%d", pcols);

	//Pointer pointer arr and mem alloc
	int **arr = (int **)malloc(rows*sizeof(int*));
	//arr mem alloc
	for(i = 0; i < rows; i++){
		arr[i] = (int *)malloc(cols * sizeof(int));
	}
	
	int row_size[rows];
	int *pnum;
	pnum = &num;
	
	//To initialize the row_array size to zero
	for(i = 0; i < rows; i++){
		row_size[i] = 0;
	} 
	
	//Random function 
	srand(time(NULL));
	
	//Asks the user to input integers
	for(k = 0; k < rows * cols; k++){
		printf("Enter an integer: ");
		scanf("%d", pnum); //pointer for the value of number
		
		//While loop to find a random row to store the integer include
		random_row = rand() % rows;
		while (row_size[random_row] == cols){
			random_row = (random_row + 1) % rows;
		}
		
		//Stores the integer in the array
		arr[random_row][row_size[random_row]]=num;
		row_size[random_row]++;
		
	}
	
	//Now to print the array
	printf("The random array is now below: \n");
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	int *psort;
	psort = &sort_row;
	
	//This asks the user to input a row to be sorted
	printf("Enter the row you want to sort: ");
	scanf("%d", psort);
	sort_row--;
	
	//To check if the row is in limit
	if(sort_row >= 0 && sort_row < rows){
		BubbleSort(arr[sort_row], cols);
		
		//To print the sorted array
		printf("\nThe sorted array is now: \n");
		for(i = 0; i < rows; i++){
			for(j = 0; j < cols; j++){
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}else{
		printf("Invalid row number.\n");
	}
	
	//Free the array memory
	for(i = 0; i < rows; i++){
		free(arr[i]);
	}
	free(arr);
	
	return 0;
}

//BubbleSort function 
void BubbleSort(int *row, int cols){
	int i, j, temp;
	int *temp_row = malloc(cols * sizeof(int));
	
	//For loop for temp row
	for(i = 0; i < cols; i++){
		temp_row[i] = row[i]; //Not the same as below
	}
	
	//Sorting loop - multi demintional array
	for(i = 0; i < cols - 1; i++){
		for(j = 0; j < cols - i -1; j++){
			if(temp_row[j] > temp_row[j + 1]){
				temp = temp_row[j];
				temp_row[j] = temp_row[j + 1];
				temp_row[j + 1] = temp;
			}
		}
	}
	for(i = 0; i < cols; i++){ //not same as above for loop fo temp row
		row[i] = temp_row[i];
	}
	free(temp_row); //Here we free the pointer temp row
}




