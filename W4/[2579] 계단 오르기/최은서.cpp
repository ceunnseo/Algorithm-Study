//언어 c++, 메모리 1112KB, 시간 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a>b ? a:b)

int main(void)
{
	int n;
	scanf("%d", &n); //계단의 수 입력
	int* dp; // dp[i] : i번째 계단을 올랐을 때 점수의 최대값
	int* arr; //각 계단의 점수 (ex. arr[1] = 10 : 첫 번째 계단의 점수)
	dp = (int*)malloc((n + 1) * sizeof(int)); 
	arr = (int*)malloc((n + 1) * sizeof(int));
  
	memset(dp, 0, (n + 1)*sizeof(int));
	memset(arr, 0, (n + 1)*sizeof(int));
  //모든 배열 0으로 초기화
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]); //각 계단의 점수 입력받음
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(dp[1] + arr[3], arr[2] + arr[3]);
	
	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(arr[i - 1] + dp[i - 3], dp[i - 2]) + arr[i];
		//printf("%d : %d\n", i, dp[i]);
	}
	printf("%d", dp[n]);

}
