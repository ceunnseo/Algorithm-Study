# (python 31256KB 168ms)

import sys
sys.setrecursionlimit(10**6)

n, m = map(int, input().split())

s = []
def backTracking():
    if len(s) == m :
        print(' '.join(map(str,s)))
        return
    
    for i in range(1, n+1):
        if i in s:
            continue
        s.append(i)
        backTracking()
        s.pop()

backTracking()