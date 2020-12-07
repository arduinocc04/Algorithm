def getColumnFalseCount(index:int):
    count = 0
    for i in range(len(inputs[index])):
        if inputs[index][i] == '0':
            count += 1
    return count

n,m = [int(i) for i in input().split()]
inputs = []
for _ in range(n):
    inputs.append(input())
k = int(input())
count = [0]*n
for i in range(n):
    a = getColumnFalseCount(i)
    if a <= k and (a%2)==(k%2):
        for j in range(n):
            if inputs[i] == inputs[j]:
                count[i] += 1
print(max(count))