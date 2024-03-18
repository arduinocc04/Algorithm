n, q = map(int, input().split())
b = [int(input()) for _ in range(n)]
t = []
for i in range(n):
    for _ in range(b[i]):
        t.append(i + 1)
for _ in range(q):
    print(t[int(input())])
