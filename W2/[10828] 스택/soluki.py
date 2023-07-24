### 언어 python3, 메모리 31256KB, 시간 56ms

# 스택의 성질
# 1. 원소의 추가 O(1)
# 2. 원소의 제거 O(1)
# 3. 제일 상단의 원소 확인 O(1)
# 4. 제일 상단이 아닌 원소들의 확인/ 변경이 불가능

# 구현
# - 배열 혹은 연결리스트를 통해 구현 할 수 있음
# - 배열을 통해 구현하는 방법이 더 쉬움

# 배열을 통한 스택 구현
# - 숫자를 담을 큰 배열 한개, 인덱스를 담을 변수 한개 필요
# - 변수는 다음에 삽입되어야 할 숫자가 들어가야할 인덱스 위치를 가르키고 있음
# - 원소는 0번지부터 담기므로, 변수는 스택 내에 담김 수의 개수를 나타내기도 함

import sys

stack = [0 for i in range(10000)]
pos = 0

def push(x: int):
    global pos
    stack[pos] = x
    pos +=  1
    
def pop():
    global pos
    if pos <= 0:
        return -1
    
    pos -= 1 
    # 들어있는 값 자체는 변경하지 않아도됨
    # 새로 들어오는 값이 덮어 쓸 예정

    return stack[pos]

def top():
    global pos
    if pos <= 0:
        return -1
    return stack[pos-1]

def size():
    global pos
    return pos

def empty():
    global pos
    if pos <= 0:
        return 1
    else:
        return 0

n = int(input())
while n > 0:
    line = sys.stdin.readline().rstrip().split()
    command = line[0]
    if command == 'push':
        push(line[1])
    elif command == 'top':
        print(top())
    elif command == 'pop':
        print(pop()) 
    elif command == 'size':
        print(size()) 
    elif command == 'empty':
        print(empty())
        
    n -= 1

# 의문점
# 1. input()과  sys.stdin.readline()은 얼마나 차이날까?
# - 시간초과 일때  sys.stdin.readline() 쓰면 통과됨
# 2. 왜 list 는 global 을 안해줘도 적용이 되는걸까?
