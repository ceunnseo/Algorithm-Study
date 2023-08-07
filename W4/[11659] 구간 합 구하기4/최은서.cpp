//언어 cpp, 메모리 1896KB, 시간 72ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 12
int main(void)
{
	int n, m;
	int* arr; //배열
	int* dp; //누적합
	int n1, n2;
	int tot = 0;
	scanf("%d %d", &n, &m);
	dp = (int*)malloc((n + 1) * sizeof(int));
	arr = (int*)malloc((n + 1) * sizeof(int));
	arr[0] = 0;
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		tot += arr[i];
		dp[i] = tot;
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &n1, &n2);
		printf("%d\n", dp[n2] - dp[n1 - 1]);
	}
}
