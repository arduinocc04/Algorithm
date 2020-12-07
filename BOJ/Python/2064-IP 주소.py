n = int(input())
ips = []
for _ in range(n):
    ips.append([int(i) for i in input().split('.')])

max_ = 5
diff = 5
for i in range(4):
    std = ips[0][i]
    for j in range(len(ips)):
        if ips[j][i]^std:
            diff = i
            if max_ == 5 or max_ < ips[j][i]^std:
                max_ = ips[j][i]^std
    if max_ != 5:  break

res = ''
for i in range(4):
    if i < diff:
        res += str(ips[0][i]) + '.'
    elif i == diff:
        j = 0
        while max_ != 0:
            max_ >>= 1
            j += 1
        res += str(ips[0][i]&int('1'*(8-j) + '0'*j, 2)) + '.'
    else:
        res += '0.'
print(res[:-1])
res = ''
for i in range(4):
    if i < diff:
        res += '255.'
    elif i == diff:
        res += str(int('11111111',2)&int('1'*(8-j) + '0'*j, 2)) + '.'
    else:
        res += '0.'
print(res[:-1])