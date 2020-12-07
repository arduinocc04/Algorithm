import math
x,k = map(int, input().split())
min_ = int((int(math.log2(x))+1)*'1',2)^x
tmp = [i for i in reversed(bin(min_)[2:])]
del min_
prev = 0
while k > 1:
    flag = False
    for i in range(prev, len(tmp)):
        if tmp[-i -1] == '0':
            tmp[-i -1] = '1'
            flag = True
            prev = i+1
            break
    if not flag:
        tmp = tmp + ['1']*(k-1)
        break
res = ''
for i in reversed(tmp):
    res += i
del tmp
print(int(res,2))