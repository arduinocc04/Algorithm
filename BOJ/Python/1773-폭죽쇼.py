n, c = map(int, input().split())
t = [0]*2_000_010
for i in range(n):
    a = int(input())
    for j in range(a, c + 1, a):
        t[j] += 1
cnt = 0
for i in range(c + 1):
    if t[i] > 0 : cnt += 1
print(cnt)
