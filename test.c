#include <stdio.h>
#include <math.h>

void cmonstart(int **arr, int size, int que, int x, int y)
{
    if(arr[x][y] == que)
        return 0;
    if(arr[x - 1][y] == 0 && (x >= 0 && x < size))
    {
        arr[x - 1][y] = que;
        cmonstart(arr[x - 1][y], size, que, x, y);
    }
}

void findway(int **arr, int size, int que)
{
    int x = -1, y = -1;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(arr[i][j] == que)
            {
                x = i;
                y = j;
                break;
            }
        }
        if(x >= 0 || y >= 0)
            break;
    }

    cmonstart(arr, size, que, x, y);

}

void pathfinder(int **tab, int size)
{
    int i, j;

    for(i = 0; i < size; i++)
    {
        findway(tab, size, i);
    }
}

int main()
{
    int arr[5][5] = {{0, 0, 0, 2, 5}, {0, 1, 0, 0, 0}, {0, 0, 0, 4, 3}, {2, 1, 5, 0, 0}, {4, 0, 0, 0, 3}};

    pathfinder(arr, 5);
}
