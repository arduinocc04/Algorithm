b, c, d = map(int, input().split())
a1, a2 = map(int, input().split())
e1, e2 = map(int, input().split())
cnt = 0
for q in range(a1*b/a2, 1_000_001):
    if a1*b < a2*q and q*e2 < e1*d:
        cnt += 1
print(cnt)