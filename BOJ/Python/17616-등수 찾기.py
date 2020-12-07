n,m,x = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    a,b = map(int, input().split())
    g[a-1].append(b-1)