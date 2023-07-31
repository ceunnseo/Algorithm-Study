// 언어 c++, apahfl 2020KB, 시간 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
void quick_sort(int st, int en, int*arr) //퀵소트 구현
{
	if (en - st <= 1) return;
	int pivot = arr[st];
	int left = st + 1;
	int right = en - 1;
	while (1)
	{
		while (left <= right && arr[left] < pivot) left++;
		while (left <= right && arr[right] > pivot) right--;
		if (left > right) break;
		swap(arr[left], arr[right]);
	}
	swap(arr[st], arr[right]);
	quick_sort(st, right, arr);
	quick_sort(left, en, arr);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int* arr;
	arr = (int*)malloc( n * sizeof(int)); //배열 동적 할당
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	quick_sort(0, n, arr); //오름차순으로 배열 정렬
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
}
