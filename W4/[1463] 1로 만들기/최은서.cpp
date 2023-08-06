//언어 cpp, 메모리 5020KB, 시간 4ms
//연산을 하는 횟수의 최솟값을 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (a<b ? a:b)

int main(void)
{
	int x;
	scanf("%d", &x);
	int* arr; //arr[i] : i를 1로 만드는 연산 횟수의 최솟값
	arr = (int*)malloc(sizeof(int) * (x + 1));
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1; 
	for (int i = 4; i <= x; i++)
	{
		arr[i] = arr[i - 1] + 1; //연산 3. (1을 뺀다)
		if (i % 3 == 0) //연산1. (3으로 나누어떨어지면 3으로 나눔)
		{
			arr[i] = min(arr[i], arr[i / 3] + 1);
		}
		if (i % 2 == 0) //연산2. (2로 나누어떨어지면 2로 나눔)
		{ 
			arr[i] = min(arr[i], arr[i / 2] + 1);
		}
		//printf("%d : %d\n", i, arr[i]);
	}
	printf("%d", arr[x]);
	
}
