import sys
sys.setrecursionlimit(10000000)
input = sys.stdin.readline
set_ = set()
n = int(input())
for j in range(n):
    a = input()
    for i in range(len(a)):
        if a[i] == '1':
            set_.add(f'{j} {i}')

def dfs(x,y):
    global cnt, set_
    cnt += 1
    if x > 0 and f'{x-1} {y}' in set_:
        set_.remove(f'{x-1} {y}')
        dfs(x-1, y)
    if x < n-1 and f'{x+1} {y}' in set_:
        set_.remove(f'{x+1} {y}')
        dfs(x+1, y)
    if y > 0 and f'{x} {y-1}' in set_:
        set_.remove(f'{x} {y-1}')
        dfs(x, y-1)
    if y < n-1 and f'{x} {y+1}' in set_:
        set_.remove(f'{x} {y+1}')
        dfs(x, y+1)

res = []
while True:
    if len(set_):
        x,y = map(int, set_.pop().split())
    else:
        break
    cnt = 0
    dfs(x, y)
    res.append(cnt)

res.sort()
print(len(res))
for i in res:
    print(i)