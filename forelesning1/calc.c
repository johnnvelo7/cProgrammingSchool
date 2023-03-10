#include <stdio.h>

int main() {
    double num1, num2, result;
    char operation;
    
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (operation) {
        case '+':
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            result = num1 / num2;
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            break;
        default:
            printf("Invalid operator\n");
    }
    return 0;
}

