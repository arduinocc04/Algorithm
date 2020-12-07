import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    ans = list(reversed([i for i in a[:n//2]] + [-i for i in a[n//2:]]))
    print(*ans)