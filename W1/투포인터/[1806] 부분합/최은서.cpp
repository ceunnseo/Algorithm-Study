// 언어 c++, 메모리 2412KB, 시간 12ms
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main(void)
{
	int n, s;
	scanf("%d %d", &n, &s);
	int* arr;
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	} 

	int en = 0; //배열 오른쪽으로 움직이는 포인터변수
	int tot = 0; //배열의 누적합 저장 변수
	int length = 200001; //누적합을 만족하는 배열 길이 저장 변수
	for (int st = 0; st < n; st++) // st : 배열의 왼쪽을 움직이는 포인터 변수
	{
		while (en < n && tot < s)
		{
			tot += arr[en];
			en += 1; //합계 >= s를 만족할 때 까지 합계 누적 & 포인터 변수 오른쪽으로 이동
		} 
		if (tot >= s) //합계 >= s인 경우
		{
			length = min(length, (en - st)); //배열 길이의 최소값 저장
			tot -= arr[st];
		}
	}
	if (length == 200001) printf("%d", 0);
	else printf("%d", length);
}
