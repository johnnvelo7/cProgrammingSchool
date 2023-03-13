#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student {

	char s_name[50];
	int s_age;
	
} stude;

int main (int iArgC, char *apszArgV[]){
	
	stude st;
	printf("Enter student detals: \n \n");
	printf("Enter student name: \t \n");
	
	scanf("%s", st.s_name);
	printf("Enter age: \n");
	scanf("%d", &st.s_age);
	printf("Input done!\n");

	return 0;
}
