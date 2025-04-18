#include <stdio.h>
#include <ctype.h>

#define MAX 10


int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}


int evaluatePostfix(char* exp) {
    int i, op1, op2, result;

    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            
            push(ch - '0');
        } else {
           
            op2 = pop();
            op1 = pop();

            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return -1;
            }
            push(result);
        }
    }

    return pop(); 
}


int main() {
    char exp[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);

    return 0;
}
