#include <stdio.h>
#define SIZE 100

char stack[SIZE][SIZE];
int top = -1;

void copy(char a[], char b[]) {
    int i = 0;
    while (b[i] != '\0') {
        a[i] = b[i];
        i++;
    }
    a[i] = '\0';
}

void push(char s[]) {
    copy(stack[++top], s);
}

void pop(char s[]) {
    copy(s, stack[top--]);
}

int isAlphaNum(char c) {
    return ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'));
}

void postfixToInfix(char postfix[], char infix[]) {
    int i = 0;
    char c, a[SIZE], b[SIZE], temp[SIZE];

    while ((c = postfix[i++]) != '\0') {
        if (isAlphaNum(c)) {
            temp[0] = c;
            temp[1] = '\0';
            push(temp);
        } else {
            pop(b);
            pop(a);
            sprintf(temp, "(%s%c%s)", a, c, b);
            push(temp);
        }
    }

    pop(infix);
}

void main() {
    char postfix[] = "ab+c*";
    char infix[SIZE];

    postfixToInfix(postfix, infix);

    printf("Postfix: %s\n", postfix);
    printf("Infix: %s\n", infix);}
