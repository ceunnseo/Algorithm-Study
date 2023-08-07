// 언어 c++ 메모리 3996KB, 시간 32ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m); //세로, 가로 크기
	int** arr;
	arr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(m * sizeof(int));
	}
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}*/

	
	// 상 하 좌 우
	int dy[4] = { - 1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	int cnt = 0;
	int tot = 0;
	int maximum = 0;

	int* queue;
	queue = (int*)malloc(sizeof(int) * (n * m * 2));
	int front = 0;
	int rear = 0;
	int ny, nx, y, x;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1)
			{
				//printf("조건 %d %d\n", i, j);
				queue[++rear] = i; //행
				queue[++rear] = j; //열
				arr[i][j] = -1; //방문처리
				tot = 1;
				while (front != rear)
				{
					y = queue[++front];
					x = queue[++front];
					for (int k = 0; k < 4; k++)
					{
						ny = y + dy[k];
						nx = x + dx[k];
						if (ny >= 0 && ny < n && nx >= 0 && nx < m) //범위 안 벗어남
						{
							if (arr[ny][nx] == 1)
							{
								queue[++rear] = ny;
								queue[++rear] = nx;
								arr[ny][nx] = -1;
								tot += 1;
							}
						}
					}
				}
				if (tot > maximum) maximum = tot;
				cnt += 1;
			}
		}
	}
	/*
	printf("결과 : \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}*/
	printf("%d\n%d", cnt, maximum);

}
