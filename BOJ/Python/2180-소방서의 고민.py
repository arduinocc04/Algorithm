import sys

input = sys.stdin.readline

n = int(input())
v = []
for _ in range(n):
    v.append([int(i) for i in input().split()])

v.sort(key = lambda x:-x[0])
time = 0
for i in range(n):
    time += (v[i][0]*time + v[i][1])
    time %= 40000
print(time)