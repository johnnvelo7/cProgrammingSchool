#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int r, c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    // Allocate memory for the 2D array
    int **arr = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
        arr[i] = (int *)malloc(c * sizeof(int));

    // Initialize the array with random integers
    srand(time(NULL));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int val = rand() % 100;  // Generate a random integer between 0 and 99
            int row = i;
            while (arr[row][j] != 0) {
                row = (row + 1) % r;
                if (row == i) {
                    printf("Error: All rows are full!\n");
                    return 1;
                }
            }
            arr[row][j] = val;
        }
    }

    // Print the array
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }

    // Sort a row
    int row_num;
    printf("Enter the row number to sort (0-%d): ", r-1);
    scanf("%d", &row_num);
    BubbleSort(arr[row_num], c);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < r; i++)
        free(arr[i]);
    free(arr);

    return 0;
}

