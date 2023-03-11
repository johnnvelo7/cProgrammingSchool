#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *arr, int n) {
    int i, j, tmp;
    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

int main() {
    int rows, cols, i, j, k;
    
    // Ask user to input the size of the array
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    int arr[rows][cols];
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Ask user to input the elements of the array
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    
    // Flatten the array into a 1D array for shuffling
    int n = rows * cols;
    int flat_arr[n];
    k = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            flat_arr[k] = arr[i][j];
            k++;
        }
    }
    
    // Shuffle the flattened array
    shuffle(flat_arr, n);
    
    // Print the shuffled array
    printf("The array in random order is:\n");
    k = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", flat_arr[k]);
            k++;
        }
        printf("\n");
    }
    
    return 0;
}

