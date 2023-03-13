#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello, world!";
    char str2[] = "Hello, friend!";
    int result = strncmp(str1 + 7, str2 + 7, 6);
    
    if (result == 0) {
        printf("The substring 'world' in str1 and the substring 'friend' in str2 are equal.\n");
    } else if (result < 0) {
        printf("The substring 'world' in str1 is less than the substring 'friend' in str2.\n");
    } else {
        printf("The substring 'world' in str1 is greater than the substring 'friend' in str2.\n");
    }
    
    return 0;
}

