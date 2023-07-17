### 언어 python3, 메모리 115656KB, 시간 1076ms

import sys

n = int(input())
cards = list(map(int, sys.stdin.readline().rstrip().split()))

m = int(input())
numbers = list(map(int, sys.stdin.readline().rstrip().split()))

num_dict = {}
for number in numbers:
    num_dict[number] = 0

for card in cards:
    try:
        if num_dict[card]>=0:
            num_dict[card] += 1
    except:
        ...

for number in numbers:
    print(num_dict[number], end=' ')
