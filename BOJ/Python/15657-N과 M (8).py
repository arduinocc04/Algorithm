import sys
from copy import deepcopy
input = sys.stdin.readline

def calc(prev, things):
    global ans, m
    things.append(prev)
    if len(things) == m:
        tmp = ""
        for i in things:
            tmp += str(a[i]) + " "
        tmp.rstrip()
        ans.add(tmp)
        return
    for i in range(prev, len(a)):
        calc(i, deepcopy(things))

n, m = map(int, input().split())
a = [int(i) for i in input().split()]
a = set(a)
a = list(a)
a.sort()
ans = set()
for i in range(len(a)): calc(i, [])
ans = sorted(list(ans))
for i in ans:
    print(i)