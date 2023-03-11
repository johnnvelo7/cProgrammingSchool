#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//This is the bubble sorting function 
void BubbleSort (int *row, int cols){
	int i, j, temp;
	int *temp_row = malloc(cols * sizeof(int));
	for (i = 0; i < cols; i++){
		temp_row[i] = row[i];
	}
	for(i = 0; i < cols - 1; i++){
		for(j = 0; j < cols - i - 1; j++){
			if(temp_row[j] > temp_row[j + 1]){
				temp = temp_row[j];
				temp_row[j] = temp_row[j + 1];
				temp_row[j + 1] = temp;
			}
		}
	}
	for(i = 0; i < cols; i++){
		row[i] = temp_row[i];
	}
	free(temp_row); //This one free the pointer for temp_row 
}


int main (){
	int rows, cols, i, j, k, num, random_row, sort_row;

	//Asks the user about the array size
	printf("Please enter the number of rows: ");
	scanf("%d", &rows);
	
	printf("Please enter the number of collumns: ");
	scanf("%d", &cols);
	
	int **arr = (int **)malloc(rows * sizeof(int*));
	for (i = 0; i < rows; i++){
		arr[i] = (int *)malloc(cols * sizeof(int));
	}
	
	int row_size[rows];
	
	//initialize the row_size array to zero
	for(i = 0; i < rows; i++){
		row_size[i] = 0;
	}
	
	//Set the random number 
	srand(time(NULL));
	
	//Asks the user to input the integers 
	for (k = 0; k < rows * cols; k++){
		printf("Enter an integer: ");
		scanf("%d", &num); //the value of num is the integers
		
		//Find a random row to store the integer 
		random_row = rand() % rows;
		while (row_size[random_row] == cols){
			random_row = (random_row + 1) % rows;
		}
		
		//store the integer in the array
		arr[random_row][row_size[random_row]]=num;
		row_size[random_row]++;
	}
	
	//Print the array 
	printf("The random array is now: \n");
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	//Asks the user to input a row to sort_row
	printf("Enter the row number you want to sort: ");
	scanf("%d", &sort_row);
	sort_row--;
	
	//Check fi the row is within bounds 
	if (sort_row >= 0 && sort_row < rows){
		BubbleSort(arr[sort_row], cols);
		
		//Print the sorted row
		printf("\nThe sorted array is: \n");
   	for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
		
	}else {
		printf("Invalid row number.\n");
	}
	
	for (i = 0; i < rows; i++){
		free(arr[i]);
	}
	free(arr);
	
	
	return 0;
	
}
