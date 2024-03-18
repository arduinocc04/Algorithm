n = int(input())
a = [int(input()) for _ in range(n)]
cnt = 0
last_max = -1
for i in a:
    if last_max < i:
        last_max = i
        cnt += 1
print(cnt)
a = a[::-1]
cnt = 0
last_max = -1
for i in a:
    if last_max < i:
        last_max = i
        cnt += 1
print(cnt)
