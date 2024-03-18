n, m, k = map(int, input().split())
t = -1
for i in range(k + 1):
    g = n - i
    b = m - (k - i)
    t = max(t, min(g//2, b))
print(t)
