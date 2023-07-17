// 언어 c++, 메모리 17644KB, 시간 784ms
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int a[1000001];
int b[1000001];
int res[2000002]; // 두 배열의 합 저장
int main(void)
{
	int n, m;
	int idx_a = 0;
	int idx_b = 0;
	scanf("%d %d", &n, &m); //배열 a, b의 크기 입력
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]); //배열 a의 원소 입력
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]); // 배열 b의 원소 입력
	}

	for (int i = 0; i < n + m; i++)
	{
		if (idx_a >= n && idx_b < m) res[i] = b[idx_b++]; //배열 a 원소는 모두 넣었다면 남아있는 b원소 넣고 인덱스 + 1
		else if(idx_b >= m && idx_a < n) res[i] = a[idx_a++]; //배열 b 원소는 모두 넣었다면 남아있는 a원소 넣고 인덱스 + 1
		else // 배열 a도 배열 b도 아직 탐색중이라면 -> 더 작은 값을 넣고, 인덱스 +1
		{
			if (a[idx_a] < b[idx_b]) res[i] = a[idx_a++];
			else res[i] = b[idx_b++];
		}
	}

	for (int i = 0; i < n + m; i++)
		printf("%d ", res[i]); //결과 출력
}
