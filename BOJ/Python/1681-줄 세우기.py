n, l = map(int, input().split())
l = str(l)
for i in range(1, 2_000_000):
    if l in str(i): continue
    n -= 1
    if n == 0: print(i)
