#include <stdio.h>
#define mx 100005
long long array[mx], left[mx], right[mx], value[mx], query[mx], mul[mx];
int n, m, k, x, y;
int main()
{
	int i;
	scanf("%d %d %d", &n, &m, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%I64d", &array[i]);
	}
	for ( i = 1; i <= m; i++)
	{
		scanf("%I64d %I64d %I64d", &left[i], &right[i], &value[i]);
	}
	for (i = 0; i <= m; i++)
	{
		query[i] = 0;
		mul[i] = 0;
	}
	for ( i = 1; i <= k; i++)
	{
		scanf("%d %d", &x, &y);
		query[x ]++;
		query[y+1]--;
	}
	for (i = 1; i <= m; i++)
	{
		query[i]  += query[i-1];

	}
	for (i = 1; i <= m; i++)
	{
		mul[left[i]] += (value[i] * query[i]);
		mul[right[i]+1] -= (value[i] * query[i]);
	}
	for (i = 1; i <= n; i++)
	{
		mul[i] += mul[i - 1];
	}
	for (i = 1; i <= n; i++)
	{
		printf("%I64d ", mul[i] + array[i]);
	}
	return 0;
}