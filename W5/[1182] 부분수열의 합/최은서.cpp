//언어 cpp 메모리 1116KB, 시간 4ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int arr[30];
int n, s; //정수 개수, 합
int cnt = 0;

void func(int cur, int tot)
{
	if (cur == n)
	{
		if (tot == s)
		{
			cnt += 1;
		}
		return;
	}
	func(cur + 1, tot);
	func(cur + 1, tot + arr[cur]);
}



int main(void)
{
	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	func(0, 0);
	if (s == 0) cnt--;
	printf("%d", cnt);
}
