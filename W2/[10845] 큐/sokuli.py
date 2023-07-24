### 언어 python3, 메모리 31256KB, 시간 52ms

# 큐
# 한쪽 끝에서 넣고 반대 쪽에서 나옴
# - 먼저 들어가면 먼저 나옴 (FIFO)

# 큐의 성질
# 1. 원소의 추가 O(1)
# 2. 원소의 제거 O(1)
# 3. 제일 앞/뒤의 원소 확인 O(1)
# 4. 제일 앞/뒤 원소 확인 불가능 O(1)

# 큐의 규현
# - 큰 배열 한개, 앞 & 뒤 가르킬 변수 2개

queue = [0 for i in range(10005)]
head = 0
tail = 0

def push(x: int):
    global head, tail

    queue[tail] = x
    tail += 1

def pop():
    global head, tail
    if empty() == 1:
        return -1

    head += 1
    return queue[head-1]

def front():
    global head, tail
    if empty() == 1:
        return -1

    return queue[head]

def back():
    global head, tail
    if empty() == 1:
        return -1

    return queue[tail-1]

def size():
    global head, tail
    return tail - head 

def empty():
    global head, tail
    if tail == head:
        return 1
    else:
        return 0

import sys

n = int(input())
while n > 0:
    line = sys.stdin.readline().rstrip().split()
    c = line[0]
    if c == 'push':
        push(line[1])
    elif c=='pop':
        print(pop())
    elif c=='size':
        print(size())
    elif c=='empty':
        print(empty())
    elif c=='front':
        print(front())
    elif c=='back':
        print(back())

    n -= 1

