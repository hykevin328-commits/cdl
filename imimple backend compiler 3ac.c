
#include <stdio.h>
#include <string.h>

int main()
{
    int n, i;
    char result[10], op1[10], op2[10], op[5];

    printf("Enter number of instructions: ");
    scanf("%d", &n);

    printf("Enter three address code:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%s %s", result, op);

        if (strcmp(op, "=") == 0)
        {
            scanf("%s", op1);

            printf("MOV AX, %s\n", op1);
            printf("MOV %s, AX\n", result);
        }
        else
        {
            scanf("%s %s", op1, op2);

            printf("MOV AX, %s\n", op1);

            if (strcmp(op, "+") == 0)
                printf("ADD AX, %s\n", op2);
            else if (strcmp(op, "-") == 0)
                printf("SUB AX, %s\n", op2);
            else if (strcmp(op, "*") == 0)
                printf("MUL %s\n", op2);
            else if (strcmp(op, "/") == 0)
                printf("DIV %s\n", op2);

            printf("MOV %s, AX\n", result);
        }
    }

    return 0;
}
