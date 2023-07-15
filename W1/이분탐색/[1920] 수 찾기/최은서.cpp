// 이분탐색 구현 -> 언어 c++ 메모리 2412KB 시간 76ms
// stl 함수 사용 -> 언어 c++ 메모리 2412KB 시간 76ms
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main(void) //stl 함수 사용
{
	int n;
	scanf("%d", &n);
	int* arr;
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int m;
	int x;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &x);
		printf("%d\n", binary_search(arr, arr+n, x));
	}
}


/* 이분탐색 직접 구현
int check(int x, int* arr, int n)
{
	int st = 0;
	int en = n - 1;
	int mid;
	while (st <= en)
	{
		mid = (st + en) / 2;
		if (arr[mid] < x)
		{
			st = mid + 1;
		}
		else if (arr[mid] > x)
		{
			en = mid - 1;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int* arr;
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int m;
	int x;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &x);
		printf("%d\n", check(x, arr, n));
	}
}
*/
