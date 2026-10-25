
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char exp[100], op1, op2, op;
    int i, temp = 1;

    printf("Enter expression: ");
    scanf("%s", exp);

    printf("\nThree Address Code:\n");

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '*' || exp[i] == '/')
        {
            op = exp[i];
            op1 = exp[i - 1];
            op2 = exp[i + 1];

            printf("t%d = %c %c %c\n", temp, op1, op, op2);

            exp[i - 1] = '0' + temp;

            for (int j = i; exp[j + 1] != '\0'; j++)
                exp[j] = exp[j + 2];

            temp++;
            i--;
        }
    }

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '+' || exp[i] == '-')
        {
            op = exp[i];
            op1 = exp[i - 1];
            op2 = exp[i + 1];

            printf("t%d = %c %c %c\n", temp, op1, op, op2);
            temp++;
        }
    }

    return 0;
}
