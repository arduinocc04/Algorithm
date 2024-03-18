import math
a = [int(i) for i in input().split()]

m = 987654321
for i in range(len(a)):
    for j in range(i + 1, len(a)):
        for k in range(j + 1, len(a)):
            m = min(m, math.lcm(math.lcm(a[i], a[j]), a[k]))
print(m)
