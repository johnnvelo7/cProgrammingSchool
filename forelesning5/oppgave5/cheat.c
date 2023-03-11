#include <stdlib.h>

void sort_row(int row, int c) {
    int i, j, temp;
    for (i = 0; i < c; i++) {
        for (j = i + 1; j < c; j++) {
            if (row[i] > row[j]) {
                temp = row[i];
                row[i] = row[j];
                row[j] = temp;
            }
        }
    }
}

int main() {
    int r, c, i, j, k, num, row_index = 0;
    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of columns: ");
    scanf("%d", &c);
    int arr[r][c];

    for (i = 0; i < r c; i++) {
        printf("Enter an integer: ");
        scanf("%d", &num);
        if (row_index == r) {
            row_index = 0;
        }
        arr[row_index][i % c] = num;
        row_index++;
    }

    printf("The array: \n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (k = 0; k < r; k++) {
        sort_row(arr[k], c);
    }

    printf("The sorted array: \n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
