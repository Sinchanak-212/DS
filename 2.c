
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack[top--];
}

int main() {
    char exp[100];
    char *e;
    int n1, n2, n3, num;

    printf("Enter the postfix expression: ");
    fgets(exp, sizeof(exp), stdin); // safer than gets()
    e = exp;

    while (*e != '\0') {
        if (isdigit(*e)) {
            num = *e - '0'; // convert char to int
            push(num);
        }
        else if (*e == '+' || *e == '-' || *e == '*' || *e == '/') {
            n1 = pop();
            n2 = pop();

            switch (*e) {
                case '+': n3 = n2 + n1; break;
                case '-': n3 = n2 - n1; break;
                case '*': n3 = n2 * n1; break;
                case '/':
                    if (n1 == 0) {
                        printf("Error: Division by zero!\n");
                        exit(1);
                    }
                    n3 = n2 / n1;
                    break;
            }
            push(n3);
        }
        e++;
    }

    if (top == 0)
        printf("The result of the expression %s= %d\n", exp, pop());
    else
        printf("Error: Invalid postfix expression!\n");

    return 0;
}


