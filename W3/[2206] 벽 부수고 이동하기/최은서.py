# 언어 python 메모리 192072 KB, 시간 6652ms

from collections import deque

n, m = map(int, input().split()) #세로 가로
graph = []

# visited[x][y][0] 벽 파괴 가능. [x][y][1]은 불가능.
visited = [[[0] * 2 for _ in range(m)] for _ in range(n)]
visited[0][0][0] = 1

for i in range(n):
    graph.append(list(map(int, input())))

# 상하좌우
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

flag = 0

queue = deque([[0, 0, 0]])
while queue:
    y, x, z = queue.popleft()
    #print(x, y, z)
    if y == n-1 and x == m-1:
        flag = 1
        break
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or ny >= n or nx < 0 or nx >= m: #범위 벗어남
            continue
        if graph[ny][nx] == 1 and z == 0: #벽이고 아직 부신 적 없음
            visited[ny][nx][1] = visited[y][x][0] + 1
            queue.append([ny, nx, 1])
        elif graph[ny][nx] == 0 and visited[ny][nx][z] == 0: #벽 아니고 이전에 간 적 없음
            visited[ny][nx][z] = visited[y][x][z] + 1
            queue.append([ny, nx, z])

if (flag == 1):
    print(visited[y][x][z])
else:
    print(-1)
