# 1s 192MB (solved 34140KB 72ms)
# N×M크기의 배열로 표현되는 미로
# 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸
#  (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램

#  input
# 첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)
# 다음 N개의 줄에는 M개의 정수로 미로
# 붙어서 입력으로 주어짐

# output
# 첫째 줄에 지나야 하는 최소의 칸 수를 출력

class miro():
    def __init__(self):
        self.n, self.m = map(int, input().split())
        self.miro = []

        for i in range(self.n):
            self.miro.append(list(map(int, sys.stdin.readline().strip())))


    def bfs(self):
        dx = [1, 0, -1, 0]
        dy = [0, 1, 0, -1]

        deq = deque()
        deq.append((0,0))
        while deq:
            x, y = deq.popleft()

            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]

                if (nx<0 or nx>=self.n or ny<0 or ny>=self.m): continue
                if (self.miro[nx][ny]== 0): continue
                if (self.miro[nx][ny]== 1):
                    self.miro[nx][ny] = self.miro[x][y] + 1 #기준점 + 1
                    deq.append((nx, ny))
        
        return self.miro[self.n-1][self.m-1]


import sys
from collections import deque

print(miro().bfs())