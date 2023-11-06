import sys
input = sys.stdin.readline

n, m = map(int, input().split())

names = {}
reverse_names = {}
for i in range(n):
    tmp = input().rstrip().split()[-1]
    names[tmp] = i
    reverse_names[i] = tmp
p = [i for i in range(510)]

def find(n):
    global p
    if n == p[n]: return n
    p[n] = find(p[n])
    return p[n]

def merge(n1, n2, b):
    global p
    n1 = find(n1)
    n2 = find(n2)
    if b == 1:
        p[n2] = n1
    else:
        p[n1] = n2

for i in range(m):
    a = input().split(",")
    k1 = names[a[0].split()[-1]]
    k2 = names[a[1].split()[-1]]
    w = int(a[-1])
    merge(k1, k2, w)
cnt = 0
for i in range(n):
    if p[i] == i:
        cnt += 1
print(cnt)
for i in range(n):
    if p[i] == i:
        print(f"Kingdom of {reverse_names[i]}")
