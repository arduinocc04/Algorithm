import sys
input = sys.stdin.readline
def print(a, end='\n'):
    sys.stdout.write(f'{a}{end}')
def getParent(n):
    global p, dist
    if p[n] == n:  return n
    p[n] = getParent(p[n])
    return p[n]
def union(n1,n2):
    global p, dist
    p[n1] = n2
    dist[n2] = (abs(n1-n2) + dist[n1])%1000
    dist[n1] = 0
for _ in range(int(input())):
    n = int(input())
    p = [i for i in range(n+1)]
    dist = [0]*(n+1)
    while True:
        cmd = input().split()
        if cmd[0] == 'O':  break
        if cmd[0] == 'E':
            print(dist[getParent(int(cmd[1]))])
        else:
            i,j = map(int, cmd[1:])
            union(i,j)