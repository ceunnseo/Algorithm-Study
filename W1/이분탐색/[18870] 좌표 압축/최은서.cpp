// 언어 c++, 메모리 12088KB, 시간 604ms
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
vector<int> uni;
int* x;
int check(int arr)
{
	int mid;
	int st = 0;
	int en = uni.size() - 1;
	while (st <= en)
	{
		mid = (st + en) / 2;
		if (uni[mid] == arr)
		{
			return mid;
		}
		else if (uni[mid] < arr)
		{
			st = mid + 1;
		}
		else //mid > arr[idx]
		{
			en = mid - 1;
		}
	}
}

int main(void) //stl 함수 사용
{
	int size;
	int n;
	scanf("%d", &n);
	x = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
		uni.push_back(x[i]);
	}
	// 배열 중복 제거 방법
	sort(uni.begin(), uni.end()); //1. 정렬을 한다.
	uni.erase(unique(uni.begin(), uni.end()), uni.end());
	//2. 중복 원소들을 vector의 제일 뒷부분으로 보낸다 -> unique
	//3. 중복된 원소들이 모여있는 뒷부분을 삭제한다. -> erase
	for (int i = 0; i < n; i++)
	{
		printf("%d ", check(x[i]));
	}
}
