// 언어 c++ 메모리 43884KB, 시간 112ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
int main(void)
{
	int m, n; //가로칸, 세로칸
	scanf("%d %d", &m, &n);
	int** graph;
	graph = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		graph[i] = (int*)malloc(m * sizeof(int));
		//memset(graph[i], 0, sizeof(int) * m);
	}
	int goal = 0; //익어야 하는 토마토 개수
	int cnt = 0; //익은 토마토 개수
	int day = 0; //최대 익은 날짜
	int queue[SIZE];
	int front = 0;
	int rear = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 0) goal += 1;
			else if (graph[i][j] == 1)
			{
				queue[++rear] = i;
				queue[++rear] = j; //토마토 위치 큐에 저장
			}
		}
	}

	//상 하 좌 우
	int dy[4] = {-1, 1, 0, 0};
	int dx[4] = { 0, 0, -1, 1 };
	int y, x, ny, nx;
	int final_x, final_y;
	while (front != rear)
	{
		y = queue[++front];
		x = queue[++front];
		for (int k = 0; k < 4; k++)
		{
			ny = y + dy[k];
			nx = x + dx[k];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m)
			{
				if (graph[ny][nx] == 0)
				{
					queue[++rear] = ny;
					queue[++rear] = nx;
					graph[ny][nx] = graph[y][x] + 1;
					cnt += 1;
					if (day < graph[ny][nx]) day = graph[ny][nx];
					final_y = ny;
					final_x = nx;
				}
			}
		}
	}

	if (cnt < goal) printf("-1");
	else if (goal == 0) printf("0");
	else printf("%d", day-1);

	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	printf("%d %d", cnt, goal);*/
	
}
