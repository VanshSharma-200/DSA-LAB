#include <stdio.h>
#define size 100

char stack[size];
int top = -1;

void push(char ch)
{
    top++;
    stack[top] = ch;
}

char pop()
{
    char ch;
    ch = stack[top];
    top--;
    return ch;
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void main()
{
    char infix[size], postfix[size];
    int i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        /* Check for operand */
        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9'))
        {
            postfix[j] = ch;
            j++;
        }

        /* Opening bracket */
        else if (ch == '(')
        {
            push(ch);
        }

        /* Closing bracket */
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }

            pop();   /* Remove '(' */
        }

        /* Operator */
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[j] = pop();
                j++;
            }

            push(ch);
        }
    }

    /* Pop remaining operators */
    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s", postfix);
}
