### 언어 python3, 메모리 31256KB, 시간 220ms

# 스택의 활용
# 수식의 괄호 쌍
# 1. 여는 괄호가 나오면 스택에 추가
# 2. 닫는 괄호가 나왔을 경우
#  2-1 스택이 비어있으면 올바르지 않은 괄호쌍
#  2-2 스택의 top이 짝이 맞지 않는 괄호일 경우 올바르지 않은 괄호 쌍
#  2-3 스택의 top이 짝이 맞는 괄호일 경우 pop
# 3. 모든 과정을 끝낸 후 스택에 괄호가 남아있으면 올바르지 않은 괄호쌍
sentences = []
while True:
    sentence = input()
    if sentence == '.':
        break
    sentences.append(sentence)
    

answers =[]
for sentence in sentences:
    stack = []
    pos = 0

    line = list(sentence)
    for item in line:
        if item == '(' or item =='[':
            stack.append(item)
        elif item ==')' :
            if len(stack) == 0:
                answers.append('no')
                break
            elif stack[-1] =='(':
                stack.pop()
            else:
                answers.append('no')
                break
                
        elif item ==']': 
            if len(stack) == 0:
                answers.append('no')
                break
            elif stack[-1] =='[':
                stack.pop()
            else:
                answers.append('no')
                break
               
        elif item =='.':
            if len(stack) == 0:
                answers.append('yes')
                break
                
            else:
                answers.append('no')
                break

for answer in answers:
    print(answer)
                
    

