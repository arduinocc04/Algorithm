l = int(input())
n = int(input())
used = [False]*1010
cnt = [0]*1010
mm = 0
mi = 0
for i in range(n):
    a, b = map(int, input().split())
    if b - a + 1 > mm:
        mi = i
        mm = b - a + 1
    for x in range(a, b + 1):
        if not used[x]:
            used[x] = True
            cnt[i] += 1
print(mi + 1)
mmmm = max(cnt)
for i in range(len(cnt)):
    if cnt[i] == mmmm:
        print(i + 1)
        break
