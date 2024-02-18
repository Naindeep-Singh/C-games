#include <stdio.h>

char entry[7][7], player;
int over = 0;

void clear() // clearing board
{
    for (int k = 1; k <= 7; k++)
        for (int i = 0; i <= 7; i++)
            entry[k][i] = ' ';
}

void board() // creation of board
{
    printf("\n");
    for (int k = 1; k <= 7; k++)
    {
        printf("\t");
        for (int l = 1; l <= 7; l++)
        {
            if (entry[k][l] == '#')
                printf("\033[1;33m|\033[0m\033[1;36m%c\033[0m", entry[k][l]);
            else if (entry[k][l] == 'O')
                printf("\033[1;33m|\033[0m\033[1;31m%c\033[0m", entry[k][l]);
            else
                printf("\033[1;33m|\033[0m%c", entry[k][l]);
        }

        printf("\033[1;33m|\033[0m");
        printf("\n");
    }
    printf("\n\t 1 2 3 4 5 6 7\n");
}

void winner(int check) // checking for winner
{
    if (check == 4)
    {
        printf("\033[0;31m************************\nPlayer %c is the winner\n************************\033[0m\n", player);
        over = 1;
    }
}

void compute(int row, int col) // looking for end of game
{
    int x = row;
    int y = col;
    int check = 0;

    // horizontal check
    for (int i = 1; i < +7; i++)
    {
        if (entry[x][i] == player)
            check++;
        else
            check = 0;
        winner(check);
    }

    // vertical check
    check = 0;
    for (int i = 1; i <= 7; i++)
    {
        if (entry[i][y] == player)
            check++;
        else
            check = 0;
        winner(check);
    }

    // right diagonal check
    check = 0;
    for (;; x--, y--)
        if (x == 1 || y == 1)
            break;
    for (; x <= 7 || y <= 7; x++, y++)
    {
        if (entry[x][y] == player)
            check++;
        else
            check = 0;
        winner(check);
    }

    // left diagonal check
    check = 0;
    for (;; row--, col++)
        if (row == 1 || col == 7)
            break;
    for (; row <= 7 || col >= 1; row++, col--)
    {
        if (entry[row][col] == player)
            check++;
        else
            check = 0;
        winner(check);
    }
}

void main() // taking input
{
    int choice, i, j, loop = 1, again;
    do
    {
        clear();
        board();
        for (i = 1; i <= 49; i++)
        {
            over = 0;
            if (i % 2 != 0)
            {
                loop = 1; // input for player #
                player = '#';
                while (loop == 1)
                {
                    printf("player # enter your choice (1-7) : ");
                    scanf("%d", &choice);

                    for (j = 7; j >= 1; j--)
                        if (entry[j][choice] == ' ')
                        {
                            entry[j][choice] = player;
                            loop = 0;
                            break;
                        }
                    if (j == 0)
                        printf("the column is full try again\n"); // checking if the entered column is completely filled
                }
                board();
                compute(j, choice);
            }

            else
            {
                loop = 1; // input for player O
                player = 'O';
                while (loop == 1)
                {
                    printf("player O enter your choice (1-7) : ");
                    scanf("%d", &choice);

                    for (j = 7; j >= 1; j--)
                        if (entry[j][choice] == ' ')
                        {
                            entry[j][choice] = player;
                            loop = 0;
                            break;
                        }
                    if (j == 0)
                        printf("the column is full try again\n");
                }
                board();
                compute(j, choice);
            }
            if (over == 1)
                break;
        }
        printf("\nPress 1 to continue and 0 to stop : "); // option to continue game
        scanf("%d", &again);
    } while (again == 1);
}