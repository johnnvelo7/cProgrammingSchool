#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubble_sort(int *row, int cols) {
    int i, j, temp;
    for (i = 0; i < cols - 1; i++) {
        for (j = 0; j < cols - i - 1; j++) {
            if (row[j] > row[j + 1]) {
                temp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = temp;
            }
        }
    }
}

int main() {
    int r, c, i, j, k, num, rand_row, sort_row;
    
    // Ask user to input the size of the array
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    
    int arr[r][c];
    int row_size[r];
    
    // Initialize row_size array to zero
    for (i = 0; i < r; i++) {
        row_size[i] = 0;
    }
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Ask user to input integers
    for (k = 0; k < r * c; k++) {
        printf("Enter an integer: ");
        scanf("%d", &num);
        
        // Find a random row to store the integer
        rand_row = rand() % r;
        while (row_size[rand_row] == c) {
            rand_row = (rand_row + 1) % r;
        }
        
        // Store the integer in the array
        arr[rand_row][row_size[rand_row]] = num;
        row_size[rand_row]++;
    }
    
    // Print the array
    printf("The array is:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    // Ask user to input a row to sort
    printf("\nEnter the row number you want to sort: ");
    scanf("%d", &k);
    k--;
    bubble_sort(arr[k], c);

    printf("\nThe sorted array is: \n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}


