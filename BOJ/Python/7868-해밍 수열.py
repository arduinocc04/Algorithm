p1,p2,p3,i = map(int, input().split())
result = list()

for j in range(60):
    b = p1**j
    for k in range(60):
        c = p2**k
        a = b*c
        result.append(a)
        for l in range(60):
            if j + k + l >= 59:
                break
            a *= p3
            result.append(a)
result.sort()
print(result[i])