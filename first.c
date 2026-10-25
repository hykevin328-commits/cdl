
#include <stdio.h>
#include <string.h>

char prod[10][20], first[26][20];
int n;

void add(char set[], char c)
{
    int i;

    for (i = 0; set[i]; i++)
        if (set[i] == c)
            return;

    set[i] = c;
    set[i + 1] = '\0';
}

int isNT(char c)
{
    return c >= 'A' && c <= 'Z';
}

void FIRST(char c, char result[])
{
    int i, j;

    if (!isNT(c))
    {
        add(result, c);
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (prod[i][0] == c)
        {
            for (j = 2; prod[i][j]; j++)
            {
                if (!isNT(prod[i][j]))
                {
                    add(result, prod[i][j]);
                    break;
                }

                FIRST(prod[i][j], result);

                if (!strchr(first[prod[i][j] - 'A'], '#'))
                    break;
            }
        }
    }
}

int main()
{
    int i;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (use # for epsilon):\n");

    for (i = 0; i < n; i++)
        scanf("%s", prod[i]);

    for (i = 0; i < n; i++)
        FIRST(prod[i][0], first[prod[i][0] - 'A']);

    printf("\nFIRST:\n");

    for (i = 0; i < n; i++)
    {
        if (i == 0 || prod[i][0] != prod[i - 1][0])
            printf("FIRST(%c) = { %s }\n",
                   prod[i][0], first[prod[i][0] - 'A']);
    }

    return 0;
}
