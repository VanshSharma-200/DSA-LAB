#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char* str) {
    if (top < MAX - 1) strcpy(stack[++top], str);
}

void pop(char* str) {
    if (top >= 0) strcpy(str, stack[top--]);
}

int is_alphanumeric(char ch) {
    return ((ch >= 'a' && ch <= 'z') || 
            (ch >= 'A' && ch <= 'Z') || 
            (ch >= '0' && ch <= '9'));
}

void postfixToInfix(char* postfix, char* infix) {
    int i = 0;
    char ch;
    char op1[MAX], op2[MAX], temp[MAX];

    while ((ch = postfix[i++]) != '\0') {
        if (is_alphanumeric(ch)) {
            temp[0] = ch;
            temp[1] = '\0';
            push(temp);
        } else {
            pop(op2);
            pop(op1);
            sprintf(temp, "(%s%c%s)", op1, ch, op2);
            push(temp);
        }
    }
    pop(infix);
}

int main() {
    char postfix[MAX] = "abcd^e-fgh*+^*+i-";
    char infix[MAX];

    postfixToInfix(postfix, infix);
    printf("Postfix: %s\n", postfix);
    printf("Infix:   %s\n", infix);

    return 0;
}
