### 언어 python3, 메모리 154800KB, 시간 1960ms

n =  int(input())
numbers = list(map(int, input().split()))

zip = set(numbers)
zip = list(zip)
zip.sort()

zip_dict = {}
for i in range(len(zip)):
    zip_dict[zip[i]]=i

for number in numbers:
    print(zip_dict[number], end=' ')
