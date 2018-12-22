#pragma warning(disable : 4996)
#include <stdio.h>
#include <algorithm>
#define N 200
#define _max(a, b) (a > b ? a : b)
using namespace std;
int G[N][N], result[N][N], Size[N], dap[N], check[N];
int cnt, bb = 0;
void Set(int x, int y);
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, k, l, m, n;
	int max = 0, min = 100;
	while (1)
	{
		scanf("%d %d", &m, &n);
		if (m == 100 || n == 100)
			break;
		bb = _max(bb, _max(m, n));
		G[m][n] = G[n][m] = 1;
		check[m] = check[n] = 1;
	}
	for (i = 1, j = 0; i < 100; i++)
	{
		if (check[i] == 1)
		{
			cnt = 0;
			Set(i, j);
			Size[j] = cnt;
			if (max < cnt)
			{
				max = cnt;
				k = j;
			}
			if (min > cnt)
			{
				min = cnt;
				l = j;
			}
			j++;
		}
	}
	if (j == 1)
	{
		for (i = 0; i < max; i++)
			dap[i] = result[0][i];
		sort(dap, dap + max);
		for (i = 0; i < max; i++)
			printf("%d ", dap[i]);
	}
	else
	{
		for (i = 0, j = 0; j < max; i++, j++)
			dap[i] = result[k][j];
		for (j = 0; j < min; i++, j++)
			dap[i] = result[l][j];
		sort(dap, dap + (max + min));
		for (i = 0; i < (max + min); i++)
			printf("%d ", dap[i]);
	}
	return 0;
}

void Set(int x, int y)
{
	check[x] = 0;
	result[y][cnt++] = x;
	for (int i = 1; i <= bb; i++)
	{
		if (G[x][i] == 1 && check[i] == 1)
			Set(i, y);
		//
	}
}