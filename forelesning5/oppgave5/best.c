#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int r, c, i, j, k, num, rand_row;
    
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
    
    return 0;
}

