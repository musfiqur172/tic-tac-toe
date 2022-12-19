#include <stdio.h>
#include <stdbool.h>

int win(int a[][4], int n)
{
    for (int i = 1; i <= n; i++)
    {
        // row check
        if (a[i][1] == a[i][2] && a[i][2] == a[i][3] && a[i][1] != -1)
        {
            return a[i][1];
        }
        // column check
        if (a[1][i] == a[2][i] && a[2][i] == a[3][i] && a[1][i] != -1)
        {
            return a[1][i];
        }
    }

    if (a[1][1] == a[2][2] && a[2][2] == a[3][3])
        return a[1][1];

    if (a[1][3] == a[2][2] && a[2][2] == a[3][1])
        return a[1][3];

    return -1;
}

void printCell(int a[][4], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == -1)
                printf(" ");
            if (a[i][j] == 1)
                printf("X");
            if (a[i][j] == 2)
                printf("O");

            if (j < n)
                printf("\t|\t");
        }
        printf("\n");
        if (i < n)
            printf("---------------------------------------");
        printf("\n");
    }
}

void printWin(int a[][4], int n, int who)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == who)
            {
                if (who == 1)
                    printf("X");
                else
                    printf("O");
            }
            else
            {
                printf(" ");
            }

            if (j < n)
                printf("\t|\t");
        }
        printf("\n");
        if (i < n)
            printf("---------------------------------------");
        printf("\n");
    }
}
int main()
{
    int n = 3;
    int a[4][4];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = -1;
        }
    }

    bool player1 = true;
    bool player2 = false;
    while (true)
    {

        printCell(a, n);
        if (player1 == true)
        {
            int r, c;
        flag1:
            printf("Player 1 Turn (X), Enter Row and Column : ");
            scanf("%d %d", &r, &c);
            if (a[r][c] != -1)
            {
                goto flag1;
            }
            a[r][c] = 1;
            player1 = false;
            player2 = true;
        }
        else
        {
            int r, c;
        flag2:
            printf("Player 2 Turn (O), Enter Row and Column : ");
            scanf("%d %d", &r, &c);
            if (a[r][c] != -1)
            {
                printf("Invalid Cell\n");
                goto flag2;
            }
            a[r][c] = 2;
            player2 = false;
            player1 = true;
        }

        if (win(a, n) == 1)
        {
            printf("\nPlayer 1 Won!!!\n");
            // printCell(a, n);
            printWin(a, n, 1);
            break;
        }
        else if (win(a, n) == 2)
        {
            printf("\nPlayer 2 Won!!!\n");
            // printCell(a, n);
            printWin(a, n, 2);
            break;
        }
    }

    return 0;
}