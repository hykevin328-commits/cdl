
#include <stdio.h>
#include <string.h>

char prod[10][20], first[26][20], follow[26][20];
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

void FOLLOW(char c)
{
    int i, j, k;
    char temp[20];

    for (i = 0; i < n; i++)
    {
        for (j = 2; prod[i][j]; j++)
        {
            if (prod[i][j] == c)
            {
                if (prod[i][j + 1] == '\0')
                {
                    if (prod[i][0] != c)
                    {
                        FOLLOW(prod[i][0]);

                        for (k = 0; follow[prod[i][0] - 'A'][k]; k++)
                            add(follow[c - 'A'],
                                follow[prod[i][0] - 'A'][k]);
                    }
                }
                else
                {
                    char next = prod[i][j + 1];

                    if (!isNT(next))
                    {
                        add(follow[c - 'A'], next);
                    }
                    else
                    {
                        strcpy(temp, first[next - 'A']);

                        for (k = 0; temp[k]; k++)
                            if (temp[k] != '#')
                                add(follow[c - 'A'], temp[k]);

                        if (strchr(temp, '#') && prod[i][0] != c)
                        {
                            FOLLOW(prod[i][0]);

                            for (k = 0; follow[prod[i][0] - 'A'][k]; k++)
                                add(follow[c - 'A'],
                                    follow[prod[i][0] - 'A'][k]);
                        }
                    }
                }
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

    add(follow[prod[0][0] - 'A'], '$');

    for (i = 0; i < n; i++)
        FOLLOW(prod[i][0]);

    printf("\nFOLLOW:\n");

    for (i = 0; i < n; i++)
    {
        if (i == 0 || prod[i][0] != prod[i - 1][0])
            printf("FOLLOW(%c) = { %s }\n",
                   prod[i][0], follow[prod[i][0] - 'A']);
    }

    return 0;
}
