#include <stdio.h>

int string_length(char *s) {
    int count = 0;
    while (*s != '\0') {
        count++;
        s++;
    }
    return count;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int length = string_length(str);
    printf("The length of the string is: %d\n", length);

    return 0;
}

