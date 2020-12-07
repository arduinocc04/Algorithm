import sys
input = sys.stdin.readline

a = [int(i) for i in input().split()]
n = int(input())
b = [int(i) for i in input().split()]

d = []
dA = d.append
tmp = []
tA = tmp.append
for j in range(n):
    tmp.clear()
    for i in range(6):
        tA(b[j]-a[i])
    dA(tmp)
    