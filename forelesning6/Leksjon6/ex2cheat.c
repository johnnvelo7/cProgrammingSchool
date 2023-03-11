#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000 // maximum line length

int main() {
    FILE *fp;
    char line[MAX_LEN];
    int num_consec_vowels = 0;
    int num_repeated_letter = 0;
    int num_letter_pair = 0;
    int i, j;
    
    // Open the text file for reading
    fp = fopen("adventures.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    // Read the file line by line
    while (fgets(line, MAX_LEN, fp) != NULL) {
        int len = strlen(line);
        
        // Check for consecutive vowels
        for (i = 0; i < len-1; i++) {
            if (isalpha(line[i]) && isalpha(line[i+1]) && // check that both characters are letters
                (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u') &&
                (line[i+1] == 'a' || line[i+1] == 'e' || line[i+1] == 'i' || line[i+1] == 'o' || line[i+1] == 'u')) {
                num_consec_vowels++;
            }
        }
        
        // Check for repeated letters
        for (i = 0; i < len-1; i++) {
            if (isalpha(line[i]) && line[i] == line[i+1]) {
                num_repeated_letter++;
            }
        }
        
        // Check for letter pairs
        for (i = 0; i < len-2; i++) {
            if (isalpha(line[i])) {
                for (j = i+2; j < len; j++) {
                    if (isalpha(line[j]) && (j-i-1) >= 'm' && (j-i-1) <= 'n') {
                        num_letter_pair++;
                    }
                }
            }
        }
    }
    
    // Print the results
    printf("Number of consecutive vowels: %d\n", num_consec_vowels);
    printf("Number of repeated letters: %d\n", num_repeated_letter);
    printf("Number of letter pairs: %d\n", num_letter_pair);
    
    fclose(fp);
    
    return 0;
}
