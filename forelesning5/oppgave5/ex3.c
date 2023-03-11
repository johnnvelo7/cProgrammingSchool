#include <stdio.h>
#include <string.h>

void print_vowels(char *str) {
		int i;
		for (i = 0; i < strlen(str); i++) {
		switch (str[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			printf("%c ", str[i]);
		break;
			default:
		break;
		}
	}

	printf("\n");

}

int main() {
	char str[100];
	printf("Enter a string: ");
	scanf("%s", str);

	printf("The vowels in the string are: ");
	print_vowels(str);

	return 0;
}
