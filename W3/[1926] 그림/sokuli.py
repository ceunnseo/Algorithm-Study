# 2초 128MB (solve 35940KB, 600ms)
# 그림의 개수와, 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력
# 그림이라는 것은 1로 연결된 것을 한 그림이라고 정의
# 그림의 넓이란 그림에 포함된 1의 개수
# 가로나 세로로 연결된 것은 연결이 된 것이고 대각선으로 연결이 된 것은 떨어진 그림

# 입력
# 첫째 줄에 도화지의 세로 크기 n(1 ≤ n ≤ 500), 가로 크기 m(1 ≤ m ≤ 500)
# 두 번째 줄부터 n+1 줄 까지 그림의 정보
# 0은 색칠이 안된 부분, 1은 색칠이 된 부분

# 출력
# 첫째 줄에는 그림의 개수, 둘째 줄에는 그 중 가장 넓은 그림의 넓이를 출력
# 그림이 하나도 없는 경우에는 가장 넓은 그림의 넓이는 0

import sys
from collections import deque

n, m = map(int, input().split())
picture = []
visit = []

for i in range(n):
    picture.append(list(map(int, sys.stdin.readline().strip().split())))
    visit.append([0 for i in range(m)])

deq = deque()
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


mx = 0
pic_num = 0

for i in range(n):
    for j in range(m):
        if picture[i][j] == 0 or visit[i][j]: continue
        
        pic_num += 1
        visit[i][j] = True
        deq.append((i,j))

        area = 0

        # BFS 구현
        while deq:
            area += 1
            cur = deq.popleft()
            for k in range(4):
                nx = cur[0] + dx[k]
                ny = cur[1] + dy[k]

                if (nx < 0 or nx >= n or ny < 0 or ny >= m): continue
                elif (visit[nx][ny] or picture[nx][ny]!=1): continue

                visit[nx][ny] = True
                deq.append((nx, ny))

        mx = max(mx, area)

print(pic_num)
print(mx)


