//언어cpp 메모리 1112KB, 시간 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	long* arr; //arr[i] : i번째 피보나치수
	scanf("%d", &n);
	arr = (long*)malloc((n+1) * sizeof(long)); //int형으로 했을 때 범위 초과하여 long으로 
	arr[0] = 0; //0번째 피보나치 수
	arr[1] = 1; //1번째 피보나치 수 
	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2]; //i번째 피보나치 수 = i-1번째 피보나치수 + i-2번째 피보나치 수
	}
	printf("%ld", arr[n]);
}
