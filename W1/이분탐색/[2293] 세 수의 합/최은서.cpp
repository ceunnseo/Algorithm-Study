// 언어 c++ 메모리 5112KB, 시간 64ms
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
	vector<int> v;
	int maxi = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			v.push_back(arr[i] + arr[j]);
		}
	}
	// 중복 제거하기
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (binary_search(v.begin(), v.end(), arr[j] - arr[i]))
			{
				maxi = max(arr[j], maxi);
			}
		}
	}
	printf("%d", maxi);
}
