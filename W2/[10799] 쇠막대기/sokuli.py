### 언어 python3, 메모리 KB, 시간 ms  -> 시간초과

# input
# 1. 레이저는 여는 괄호와 닫는 괄호의 인접한 쌍 ‘( ) ’ 으로 표현된다. 또한, 모든 ‘( ) ’는 반드시 레이저를 표현한다.
# 2. 쇠막대기의 왼쪽 끝은 여는 괄호 ‘ ( ’ 로, 오른쪽 끝은 닫힌 괄호 ‘) ’ 로 표현된다.

# output
# 잘려진 조각의 총 개수를 나타내는 정수를 한줄에

# idea
# 1. '(' 열리면 바로 다음에 ')' 오는지 확인
# 3. 레이저 위치를 포함한 리스트 생성(레이저일 경우 1, 아닐경우 0)
# 3. 쇠막대기 시작 인덱스 끝 인덱스 저장 후 확인

import sys

iron = list(sys.stdin.readline().rstrip()) #  쇠막대기와 레이저의 배치를 나타내는 괄호 표현, 최대 100,000개

stack = [] # 괄호의 열림 닫힘을 확인할 스택
laser = [] # 레이저 위치 인덱스
index=[] # 진행중인 쇠막대기 인덱스 [{start: 00, end: 00}]
completed_index = [] # 길이 측정이 완료된 쇠막대기 인덱스

for i in range(len(iron)):
    if iron[i] == '(': # 열림 괄호일 때
        if iron[i+1] == ')': # 바로 다음에 닫힌 괄호 오는지 확인
            laser.append(1) # 레이저일때 해당 위치에 push(1)
        else: # 레이저가 아닐때
            stack.append(iron[i]) # 괄호 스택에 열림 괄호 push 
            laser.append(0) # 레이저 아니므로 위치 인덱스 push(0)
            index.append({'start': len(laser)-1, 'end': None}) # 해당 쇠막대기 시작 인덱스 저장

    elif iron[i] ==')': # 닫힘 괄호일 때
        if iron[i-1] == '(': # 바로 이전에 열림 괄호 였는지 확인
            ... # 위에서 처리한 케이스, 넘김
        elif stack[-1] == '(': # 스택 최신 값이 열린 괄호일 때
            
            laser.append(0) # 레이저가 아니므로 push(0)
            
            index[-1]['end']= len(laser)-1 # 해당 쇠막대기 끝 인덱스 저장

            completed_index.append(index[-1]) # 완료된 쇠막대기로 이동
            index.pop() # 쇠막대기 인덱스 최신값 제거

            stack.pop() # 스택 최신값 제거
    
sum = 0 #절단 쇠막대기 개수 합
for item in completed_index: #completed_index 만큼 쇠막대기 개수
    start = item['start']
    end = item['end']

    laser_count = 0
    for i in range(start, end+1): # 쇠막대기 인덱스 사이에 레이저가 몇개 있는지 count
        if laser[i] == 1:
            laser_count += 1
    
    sum += (laser_count + 1) # 잘린 쇠막대기 개수는 (레이저 개수 + 1)

print(sum)
        



