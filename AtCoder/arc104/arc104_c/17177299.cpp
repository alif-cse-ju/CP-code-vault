#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i, j, k;
	int a[102], b[102];
	for (i = 0; i < n; i++)
		scanf("%d %d", &a[i], &b[i]);
	int v[202];
	for (i = 0; i <= 2 * n; i++)
		v[i] = -1;
	for (i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			if (v[a[i]] > 0)
			{
				printf("No\n");
				return 0;
			}
			v[a[i]] = i;
		}
		if (b[i] > 0)
		{
			if (v[b[i]] > 0)
			{
				printf("No\n");
				return 0;
			}
			v[b[i]] = n + i;
		}
	}
	int dp[202];
	for (i = 0; i <= 2 * n; i++)
		dp[i] = 0;
	dp[0] = 1;
	int c;
	for (i = 0; i < 2 * n; i++)
	{
		if (dp[i] > 0)
		{
			for (j = i + 2; j <= 2 * n; j += 2)
			{
				c = 0;
				for (k = 0; k < (j - i) / 2; k++)
				{
					if (v[i + k + 1] >= n)
						c++;
					if (v[i + k + (j - i) / 2 + 1] > 0)
					{
						if (v[i + k + (j - i) / 2 + 1] < n)
							c++;
					}
					if (v[i + k + 1] > 0 && v[i + k + (j - i) / 2 + 1] > 0)
					{
						if (v[i + k + 1] + n != v[i + k + (j - i) / 2 + 1])
							c++;
					}
				}
				if (c == 0)
					dp[j] = 1;
			}
		}
	}
	if (dp[2 * n] > 0)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}