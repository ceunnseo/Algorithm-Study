// [방법1-투포인터] 언어 c++, 메모리 2412KB, 시간 20ms
// [방법2-check 배열] 언어 c++ 메모리 10228KB, 시간 12ms
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
bool compare(int a, int b)
{
	return a > b;
} 
/* 방법1 - 투포인터
int main(void)
{
	int n;
	scanf("%d", &n);
	int en = n - 1;
	int* arr;
	int cnt = 0;
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int x;
	scanf("%d", &x);
	sort(arr, arr + n, compare); //오름차순으로 정렬
	for (int st = 0; st < en; st++)
	{
		while (arr[st] + arr[en] < x) en--;
		if (arr[st] + arr[en] == x)
		{
			cnt++;
			en--;
		}
	}
	printf("%d", cnt);
}*/

/*방법2 - check 배열
int main(void)
{
	int n;
	int maxi = -1;
	scanf("%d", &n);
	int* arr;
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if (maxi < arr[i]) maxi = arr[i]; //array의 최대값을 maxi에 저장
	}
	int x;
	scanf("%d", &x);
	int* check;
	int cnt = 0;
	check = (int*)calloc(2000001, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		if (x - arr[i] > 0)
		{
			if (check[x - arr[i]] == 1) cnt++;
		}
		check[arr[i]] = 1;
	}
	printf("%d", cnt);
}
*/
