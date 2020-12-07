_ = input()
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
a.sort()
b.sort(reverse = True)
result = 0
for i in range(len(b)):
    result += a[i]*b[i]
print(result)