//언어 cpp 메모리 1112KB, 시간 152ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int cnt;
//함수 정의 : 원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 과정을 출력하는 함수
void hanoi(int n, int a, int b) //판의 개수
{
	cnt += 1;
	if (n == 1)
	{
		printf("%d %d\n", a, b);
		return;
	}
	hanoi(n - 1, a, 6 - a - b);
	printf("%d %d\n", a, b);
	hanoi(n - 1, 6 - a - b, b);
}
int main(void)
{
	int n;
	scanf("%d", &n); //원판의 개수 입력
	printf("%d\n", (1 << n) - 1); //shift연산
	hanoi(n, 1, 3);
}
