#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Quicksort function
void QuickSort(int *arr, int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = temp;

        QuickSort(arr, left, i);
        QuickSort(arr, i + 2, right);
    }
}

// Main program
int main(int argc, char *argv[]) {
    // Variables
    int rows, cols, num, random_row, sort_row;

    // Print prompts and read input
    printf("Please enter the number of rows: ");
    scanf("%d", &rows);

    printf("Please enter the number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for the array
    int **arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Error: Out of memory\n");
            exit(1);
        }
    }

    // Initialize row_size array to zero
    int row_size[rows];
    memset(row_size, 0, sizeof(row_size));

    // Generate random numbers and populate the array
    srand(time(NULL));
    for (int i = 0; i < rows * cols; i++) {
        printf("Enter an integer: ");
        scanf("%d", &num);

        // Find a random row to store the integer in
        random_row = rand() % rows;
        while (row_size[random_row] == cols) {
            random_row = (random_row + 1) % rows;
        }

        // Store the integer in the array
        arr[random_row][row_size[random_row]] = num;
        row_size
        
    // If a row is completely filled, sort it
    if (row_size[random_row] == cols) {
        QuickSort(arr[random_row], 0, cols - 1);
        printf("Row %d sorted.\n", random_row);
    }
}

// Sort any unsorted rows
for (int i = 0; i < rows; i++) {
    if (row_size[i] > 0 && row_size[i] < cols) {
        QuickSort(arr[i], 0, row_size[i] - 1);
        printf("Row %d sorted.\n", i);
    }
}

// Print the array
printf("\n");
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < row_size[i]; j++) {
        printf("%d ", arr[i][j]);
    }
    printf("\n");
}

// Free memory
for (int i = 0; i < rows; i++) {
    free(arr[i]);
}
free(arr);

return 0;

