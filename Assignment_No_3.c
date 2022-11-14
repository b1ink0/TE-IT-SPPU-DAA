#include <stdio.h>
#include <stdbool.h>

int N = 4;

bool isSafe(int CB[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (CB[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (CB[i][j])
            return false;

    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (CB[i][j])
            return false;

    return true;
}

bool NQ(int CB[N][N], int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(CB, i, col))
        {
            CB[i][col] = 1;

            if (NQ(CB, col + 1))
                return true;

            CB[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    int board[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }
    if (NQ(board, 0)){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}