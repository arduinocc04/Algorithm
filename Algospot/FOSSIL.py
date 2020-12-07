import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n,m = map(int, input().split())
    p1X = []
    p1Y = []
    p2X = []
    p2Y = []
    p1XA = p1X.append
    p1YA = p1Y.append
    p2XA = p2X.append
    p2YA = p2Y.append
    tmp = input().split()
    for i in range(len(tmp)):
        if i%2:
            p1YA(int(i))
        else:
            p1XA(int(i))
    tmp = input().split()
    for i in range(len(tmp)):
        if i%2:
            p2YA(int(i))
        else:
            p2XA(int(i))