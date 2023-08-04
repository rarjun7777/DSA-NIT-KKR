// activity selection problem

#include <stdio.h>

void printMaxActivities(int s[] , int f[], int n)
{
    int i, j;

    printf("Following activities are selected\n");

    i = 0;
    printf("%d ", i);

    for (j = 1; j < n; j++)
    {

        if (s[j] >= f[i])
        {
            printf("%d ", j);
            i = j;
        }
    }
}

// Driver code
int main()
{
    int n;
    scanf("%d", &n);

    int s[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }

    int m;
    scanf("%d", &m);

    int f[m];

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &f[i]);
    }
    
    printMaxActivities(s, f, n);
    return 0;
}
