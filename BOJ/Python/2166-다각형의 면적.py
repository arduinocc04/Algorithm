import sys
input = sys.stdin.readline
n = int(input())
dots = [[int(i) for i in input().split()] for _ in range(n)]
def round(n:float) ->float:
    return int(n*(10)+0.5)/(10)
def getDoubledAreaOfTriangle(d1, d2, d3):
    x1,y1 = d1
    x2,y2 = d2
    x3,y3 = d3
    return ((x1*y2 + x2*y3 + x3*y1) - (x1*y3 + x3*y2 + x2*y1))
s = 0
for i in range(n-1):
    s += getDoubledAreaOfTriangle(dots[0], dots[i], dots[i+1])
print(round(abs(s)/2))