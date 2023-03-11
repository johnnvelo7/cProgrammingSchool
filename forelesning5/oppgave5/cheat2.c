#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *row, int cols) {
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
    int r, c, i, j, k = 0, count = 0;
    int **array;

    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    array = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++) {
        array[i] = (int *)malloc(c * sizeof(int));
    }

    srand(time(NULL));
    printf("Enter the integers: \n");
    for (i = 0; i < r * c; i++) {
    scanf("%d", &array[k][count]);
        count++;
        if (count == c) {
            count = 0;
            k++;
        }
        if (k == r) {
            k = 0;
        }
    }

    printf("The array is: \n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
        		int random = array[i][j];
            printf("%d ", random);
        }
        printf("\n");
    }

    printf("\nEnter the row number you want to sort: ");
    scanf("%d", &k);
    k--;
    bubbleSort(array[k], c);

    printf("\nThe sorted array is: \n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < r; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}

