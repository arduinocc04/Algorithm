n, k = map(int, input().split())
cnt = 0
f = False
for i in range(1, n):
    if n % i == 0:
        cnt += 1
    if cnt == k:
        print(i)
        f = True
        break

if not f:
    print(0)
