#include <bits/stdc++.h>

bool isPos(int i, int j, int sudoku[9][9], int x)
{
    for (int k = 0; k < 9; k++)
    {
        if (sudoku[i][k] == x || sudoku[k][j] == x || sudoku[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3] == x)
            return false;
    }
    return true;
}
bool solve(int i, int j, int sudoku[9][9])
{
    if (i == 9)
        return true;
    if (j == 9)
        return solve(i + 1, 0, sudoku);
    if (sudoku[i][j] == 0)
    {
        for (int x = 1; x <= 9; x++)
        {
            if (isPos(i, j, sudoku, x))
            {
                sudoku[i][j] = x;
                if (solve(i, j + 1, sudoku))
                    return true;
                sudoku[i][j] = 0;
            }
        }
    }
    else
    {
        return solve(i, j + 1, sudoku);
    }

    return false;
}

bool isItSudoku(int matrix[9][9])
{
    // Write your code here.
    return solve(0, 0, matrix);
}
