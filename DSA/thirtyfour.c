// rod cutting problem

#include <stdio.h>
#include <limits.h>

int max(int a, int b) { return (a > b) ? a : b; }

int cutrod(int price[], int n)
{
    int val[n + 1];
    val[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++)
            max_val = max(max_val, price[j] + val[i - j - 1]);
        val[i] = max_val;
    }

    return val[n];
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int a = 0;
    a = cutrod(arr, n);

    printf("%d", a);

    return 0;
}