b, c = map(int, input().split())
d, e = map(int, input().split())
a = [b, c, e, d]

val = -987654321
j = -1
for k in range(4):
    i = 4 - k
    tmp = a[(i)%4]/a[(i + 3)%4] + a[(i + 1)%4]/a[(i + 2)%4]
    if tmp > val:
        j = i
        val = tmp
print(4 - j)
