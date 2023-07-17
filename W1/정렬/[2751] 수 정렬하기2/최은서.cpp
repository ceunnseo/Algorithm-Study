#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
//arr[st:mid]와 arr[mid:en]을 합친다.
void merge(int st, int en, int*arr, int*temp)
{
	int mid = (st + en) / 2;
	int left = st;
	int right = mid;
	for (int i = st; i < en; i++)
	{
		if (right == en) temp[i] = arr[left++];
		else if (left == mid) temp[i] = arr[right++];
		else if (arr[left] <= arr[right]) temp[i] = arr[left++];
		else  temp[i] = arr[right++];
	}
	for (int i = st; i < en; i++) arr[i] = temp[i];
}

//array[st:en]을 정렬하는 함수
void merge_sort(int st, int en, int*arr, int*temp)
{
	if (en - st == 1) return; //배열의 길이가 1인 경우
	int mid = (st + en) / 2;
	merge_sort(st, mid, arr, temp); //왼쪽 절반을 정렬한다.
	merge_sort(mid, en, arr, temp); //오른쪽 절반을 정렬한다.
	merge(st, en, arr, temp); // 두 배열을 합친다.
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int* arr;
	int* temp;
	arr = (int*)malloc(sizeof(int) * n);
	temp = (int*)calloc(n, sizeof(int)); // 4byte짜리 배열 n개를 만들고 0으로 초기화
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	merge_sort(0, n, arr, temp);
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}
