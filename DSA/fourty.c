//Check whether a given graph is connected or not using DFS method

#include <stdio.h>
#include <conio.h>

int a[20][20], visited[20], n;

void dfs(int i)
{
    int j;
    visited[i] = 1;
    for (j = 1; j <= n; j++)
        if (a[i][j]==1 && visited[i]==0)
        {
            printf("\n %d->%d", i, j);
            dfs(i);
        }
}

int main()
{
    int i, j, count = 0;
    printf("\n Enter number of vertices:");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
        for (j = 1; j <= n; j++)
        a[i][j] = 0;
    }

    printf("\n Enter the adjacency matrix:\n");

    for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
    scanf("%d", &a[i][j]);

    dfs(1);

    printf("\n");
    
    for (i = 1; i <= n; i++)
    {
        if (visited[i])
        count++;
    }


    if (count == n)
        printf("\n Graph is connected");

    else
        printf("\n Graph is not connected");

    return 0;
}
