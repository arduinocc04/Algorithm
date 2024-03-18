n, x, k = map(int, input().split())
b = [i for i in range(n + 1)]
for _ in range(k):
    a, c =map(int, input().split())
    tmp = b[a]
    b[a] = b[c]
    b[c] = tmp
print(b.index(x))
