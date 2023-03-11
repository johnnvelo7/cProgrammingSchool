#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 1000 // maximum number of doubles in the file

int main() {
    FILE *fp, *fp_bin, *fp_txt;
    double nums[MAX_NUMS];
    int count = 0;
    
    // Open the text file for reading
    fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    // Read the doubles from the text file
    while (fscanf(fp, "%lf", &nums[count]) == 1) {
        count++;
    }
    fclose(fp);
    
    // Open the binary file for writing
    fp_bin = fopen("output.bin", "wb");
    if (fp_bin == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    // Write the doubles to the binary file
    fwrite(nums, sizeof(double), count, fp_bin);
    fclose(fp_bin);
    
    // Open the text file for writing
    fp_txt = fopen("output.txt", "w");
    if (fp_txt == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    // Open the binary file for reading
    fp_bin = fopen("output.bin", "rb");
    if (fp_bin == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    // Read the doubles from the binary file and write them to the text file
    while (fread(&nums[count], sizeof(double), 1, fp_bin) == 1) {
        fprintf(fp_txt, "%.15g\n", nums[count]);
        count++;
    }
    fclose(fp_bin);
    fclose(fp_txt);
    
    return 0;
}

