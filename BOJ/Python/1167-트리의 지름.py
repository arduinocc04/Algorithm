import sys
input = sys.stdin.readline
v = int(input())
graph = [[]for _ in range(v)]
def dfs(n, cnt, p):
    if len(graph[n]) == 1 and graph[n][0] == p:
        return (n, cnt)
    else:
        for i in graph[n]:
            if i[0] != p:
                dfs(i[0], cnt+i[1], n)
for _ in range(v):
    a = [int(i) for i in input().split()]
    for i in range((len(a)-2)//2):
        graph[a[0]-1].append([a[2*i]-1, a[2*i+1]])
a, _ = dfs(0, 0, 0)
print(dfs(a, 0, a)[0])