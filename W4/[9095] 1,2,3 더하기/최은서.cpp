//언어 cpp, 메모리 1112KB, 시간 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 12
int main(void)
{
	int t; //테스트 케이스 수
	int num; //입력받는 숫자
	int dp[MAX]; //dp[i] : i를 1, 2, 3의 합으로 표현하는 경우의 수
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 11; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &num);
		printf("%d\n", dp[num]);
	}
}
