//메모리 1112KB, 시간 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	int* dp;
	dp = (int*)malloc((n + 1) * sizeof(int));
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007; 
    //계산 중에 나눗셈 연산을 하지 않을 경우 오버플로우 발생함
	}
	printf("%d", dp[n]);
}
