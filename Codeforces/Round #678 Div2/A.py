import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n,m = map(int, input().split())
    a = [int(i) for i in input().split()]
    if sum(a) == m:
        print('YES')
    else:
        print('NO')