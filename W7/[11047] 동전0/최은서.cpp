// 언어 CPP, 메모리 1112KB, 시간 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000
int main(void)
{
	int n, m;
	int* coin;
	int cnt = 0;
	scanf("%d %d", &n, &m);
	coin = (int*)malloc(sizeof(int) * n);
	for(int i = n-1; i >= 0; i--)
	{
		scanf("%d", &coin[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (coin[i] <= m)
		{
			cnt += (m / coin[i]);
			m = m % coin[i];
		}
		if (m == 0)
		{
			break;
		}
	}
	printf("%d", cnt);

}
