// 언어 c++ 메모리 3976KB, 시간 568ms
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;
int* arr;
int n;

int lower_bound(int target)
{
	int mid = 0;
	int st = 0;
	int en = n;
	while (st < en)
	{
		mid = (st + en) / 2;
		if (arr[mid] < target) st = mid + 1;
		else en = mid; //arr[mid] >= target
	}
	return en;
}

int upper_bound(int target)
{
	int mid = 0;
	int st = 0;
	int en = n;
	while (st < en)
	{
		mid = (st + en) / 2;
		if (arr[mid] <= target) st = mid + 1;
		else en = mid; // arr[mid] > target
	}
	return en;
}

int main(void)
{
	scanf("%d", &n); //카드 개수
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);


	int m;
	int card;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &card);
		printf("%d ", upper_bound(card) - lower_bound(card));
	}
}
