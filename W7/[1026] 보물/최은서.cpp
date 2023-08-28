//언어 cpp, 메모리 1112KB, 시간 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second) return 1;
	else if (*(int*)first < *(int*)second) return -1;
	else return 0;
} //오름차순 정렬

int main(void)
{
	int n;
	int res = 0;
	int* a;
	int* b;
	scanf("%d", &n); 
	a = (int*)malloc(sizeof(int) * n);
	b = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}
	qsort(b, n, sizeof(int), compare); //오름차순
	qsort(a,  n, sizeof(int), compare); //오름차순
	for (int i = 0; i < n; i++)
	{
		res = res + (a[i] * b[n - 1- i]);
	}
	printf("%d", res);
}
