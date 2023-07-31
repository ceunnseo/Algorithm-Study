// 언어 c++, 메모리 1112KB, 시간 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, m;
	int graph[100][100];
	int queue[10000] = { 0, };
	int front = 0;
	int rear = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &graph[i][j]);
		}
	}

	int visited[100][100] = { 0, }; // 방문처리
	queue[++rear] = 0; //행 y
	queue[++rear] = 0; //열 x (enqueue)
	visited[0][0] = 1; //0,0은 방문처리


	// 상 하 좌 우
	int dy[4] = {-1, 1, 0, 0};
	int dx[4] = {0, 0, -1, 1};
	int x = 0;
	int y = 0;
	int nx, ny;
	
	while (front != rear) //큐가 빌 때 까지
	{
		y = queue[++front];
		x = queue[++front]; //dequeue
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m) //범위를 벗어나지 않았고
			{
				if (graph[ny][nx] == 1 && visited[ny][nx] == 0) // 방문 안했으면
				{
					queue[++rear] = ny;
					queue[++rear] = nx;
					visited[ny][nx] = 1; //방문처리
					graph[ny][nx] = graph[y][x] + 1;
				}
			}
		}
	}
	printf("%d", graph[n-1][m-1]);
	
}
