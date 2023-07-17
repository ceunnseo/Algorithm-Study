#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
/*
int main(void) // 언어 c++, 메모리 2412KB, 시간 1660ms
{
	int n, m;
	scanf("%d %d", &n, &m);
	int* arr;
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int min = 2000000000;
	int st = 0;
	int en = 1;
	int diff;
	while (en <= n - 1 && st <= n - 2)
	{
		diff = arr[en] - arr[st];
		if (diff >= m)
		{
			if (diff < min) min = diff;
			st += 1;
			en = st + 1;
		}
		else en += 1;
	}
	printf("%d", min);	
}*/
//언어 c++, apahfl 2412KB, 시간 28ms
int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	int* arr;
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]); //배열 원소 입력
	}
	sort(arr, arr + n); //오름차순 정렬
	int mini = 2000000000; //차이가 m이상이면서 제일 작은 값을 담는 변수
	int en = 0; //포인터 변수 en
	for (int st = 0; st < n; st++)
	{
		while (en < n and arr[en] - arr[st] < m) en++; //해당 조건을 만족할 때 까지 en 인덱스값을 1씩 증가
		if (en == n) break; //범위를 넘어가면 break
		if (mini > arr[en] - arr[st]) mini = arr[en] - arr[st];
	}
	printf("%d", mini);
}
