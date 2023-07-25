### 언어 python3, 메모리 34884KB, 시간 120ms  

import sys
from string import ascii_uppercase

n = int(input())
cal = list(input()) 
alphabet = list(ascii_uppercase)
stack = []

numbers={}
for i in range(n):
    numbers[alphabet[i]] = (int(sys.stdin.readline().strip()))

for item in cal:
    if item in alphabet: # 알파벳일 때 임시 스택에 넣음
        stack.append(numbers[item])
    else: # 수식일때  임시스택에서 숫자 2개 꺼냄
        number1 = stack[-1] 
        stack.pop()

        number2 = stack[-1]
        stack.pop()

        # 연산해서 다시 임시 스택에 추가
        if item =='+':
            stack.append(number2+number1)
        elif item =='-':
            stack.append(number2-number1)
        elif item =='*':
            stack.append(number2*number1)
        elif item =='/':
            stack.append(number2/number1)

answer = "{:.2f}".format(stack[-1])
print(answer)