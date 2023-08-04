// LCS problem

/* Dynamic Programming C implementation of LCS problem */
#include <stdio.h>
#include <string.h>

int max(int a,int b)
{
    if(a>b)
    return a;

    else
    return b;
}

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(char *X, char *Y, int m, int n)
{
	// intitalizing a matrix of size (m+1)*(n+1)
	int L[m + 1][n + 1];

	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	// L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
	return L[m][n];
}

// Driver program to test above function
int main()
{
	
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = strlen(X);
	int n = strlen(Y);

	int a=lcs(X, Y, m, n);
    printf("%d",a);

	return 0;
}
// code submitted by Aditya Yadav (adityayadav012552)
