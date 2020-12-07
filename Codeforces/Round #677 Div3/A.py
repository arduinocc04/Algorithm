import sys
input = sys.stdin.readline
def calc(n):
    if n == 1: return 1
    return n+calc(n-1)
for _ in range(int(input())):
    n = input()
    print((int(n[0])-1)*10 + calc(len(n))-len(n))