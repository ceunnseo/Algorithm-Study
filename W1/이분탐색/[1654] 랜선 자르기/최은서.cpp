// 언어 c++ 메모리 2020KB, 시간 4ms
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;
int main(void)
{
	long long low = 1;
	long long mid;
	long long high = 0;
	int k, n;
	long long cnt = 0;
	int* arr;
	long long res = 0;
	scanf("%d %d", &k, &n);
	arr = (int*)malloc(k * sizeof(int));
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &arr[i]);
		if (high < arr[i]) high = arr[i];
	}

	while (low <= high)
	{
		mid = (low + high) / 2;
		cnt = 0;
		for (int i = 0; i < k; i++)
		{
			cnt += (arr[i] / mid);
		}
		if (cnt >= n)
		{
			res = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	printf("%lld", res);
}
