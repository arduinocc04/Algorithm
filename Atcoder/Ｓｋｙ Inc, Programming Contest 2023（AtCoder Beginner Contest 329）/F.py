import sys
input = sys.stdin.readline

n, q = map(int, input().split())
c = [{int(i)} for i in input().split()]
for _ in range(q):
    a, b = map(int, input().split())
    c[b - 1] = c[b - 1] | c[a - 1]
    c[a - 1] = set()
    print(len(c[b-1]))
