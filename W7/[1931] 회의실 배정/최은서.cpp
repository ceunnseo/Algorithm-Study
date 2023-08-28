//언어 cpp, 메모리 2680KB, 시간 44ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct timeTable
{
	int start;
	int end;
}timeTable;

int compare(const void* a, const void* b)
{
	timeTable A = *(timeTable*)a;
	timeTable B = *(timeTable*)b;
	if (A.end > B.end) return 1;
	else if (A.end == B.end)
	{
		if (A.start > B.start) return 1;
		else return -1;
	}
	else return -1; 
}

int main(void)
{
	int n;
	int cnt = 1;
	int start;
	int end;
	scanf("%d", &n); //회의실의 수
	timeTable* arr;
	arr = (timeTable*)malloc(sizeof(timeTable) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &arr[i].start, &arr[i].end);
	}
	qsort(arr, n, sizeof(timeTable), compare);
	start = arr[0].start;
	end = arr[0].end;
	for (int i = 1; i < n; i++)
	{
		if (arr[i].start < end) continue;
		start = arr[i].start;
		end = arr[i].end;
		cnt += 1;
	}
	printf("%d\n", cnt);
}
