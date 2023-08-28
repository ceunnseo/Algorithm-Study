//언어 cpp, 메모리 1896KB, 시간 24ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void * first, const void * second)
{
	if (*(int*)first > *(int*)second) return -1;
	else if (*(int*)first < *(int*)second) return 1;
	else return 0;
} //내림차순 정렬

int main(void)
{
	int n;
	int * rope;
	int w; //최대중량
	scanf("%d", &n); //로프의 개수
	rope = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &rope[i]);
	} //로프가 견딜 수 있는 최대 중량
	//정렬할 배열, 배열 총 개수, 배열 원소 하나 크기, 비교 수행 함수 포인터
	qsort(rope,  n, sizeof(int), compare);
	w = rope[0];
	for (int i = 1; i < n; i++)
	{
		if (w < (rope[i] * (i + 1)))
		{
			w = rope[i] * (i + 1);
		}
	}
	printf("%d\n", w);
}
