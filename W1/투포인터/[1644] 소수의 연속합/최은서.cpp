// 언어 c++ 메모리 17664KB, 시간 108ms
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;
int* arr;
int primeNumber(int n)//n이하인 소수를 배열에 담아주는 함수
{
	int idx = 2;
	for (int i = 2; i <= n; i++)
	{
		arr[i] = i;
	}
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (arr[i] == 0)
		{
			continue; //0이면 소수가 아님
		}
		for (int j = i * i; j <= n; j += i)
		{
			if (arr[j] != 0) idx++;
			arr[j] = 0;
		}
	}
	sort(arr, arr + n+1);
	return idx; //시작 인덱스 반환
} 

int countFunc(int start, int number) //시작,입력한 숫자
{
	int cnt = 0;
	int en = 0;
	int tot = 0;
	int size = number + 1; //배열의 사이즈
	
	for(int st = start; st < size; st++)
	{
		//printf("시작인덱스 %d\n", st);
		while (en < size && tot < number) tot += arr[en++];
		//printf("%d %d %d %d\n",size,  st, en, tot);
		if (tot == number)
		{
			//printf("countFunc함수, %d %d %d %d\n",st, en, tot, number);
			cnt++;
		}
		tot = tot - arr[st];
	}
	return cnt;
}


int main(void) 
{
	int n;
	scanf("%d", &n);
	arr = (int*)calloc(n+1, sizeof(int));
	int startIdx = primeNumber(n); //시작 인덱스
	/*
	for (int i = 0; i < n + 1; i++)
	{
		printf("%d ", arr[i]);
	}
	
	printf("\n===========\n"); */
	printf("%d", countFunc(startIdx, n));//시작인덱스와 입력한 숫자 전달
}
