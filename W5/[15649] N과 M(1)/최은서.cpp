//메모리 1112KB, 시간 32ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n, m;
int arr[10]; //수열을 담을 배열
bool isused[10]; //수가 쓰인 여부를 표현
// 3, 2 -> arr[0] = 3, arr[1] = 2
//isused[3][ = true

//현재 k개까지 수를 택한 상황에서 arr[k]를 정하는 함수
void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!isused[i]) //수 i가 쓰이지 않았으면
		{
			arr[k] = i;
			isused[i] = 1; //true
			func(k + 1);
			isused[i] = 0;
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	func(0);
}
