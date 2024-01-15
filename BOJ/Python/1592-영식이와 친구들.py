n, m, l = map(int, input().split())
cnt = [0]*n
s = 0
aaaa = 0
while True:
    cnt[s] += 1
    aaaa += 1
    if cnt[s] == m: break
    if cnt[s] % 2:
        s = (s + l) % n
    else:
        s = (s - l) % n
print(aaaa - 1)
