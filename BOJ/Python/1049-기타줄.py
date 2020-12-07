n,m = [int(i) for i in input().split()]

minSix = 1001
minOne = 1001
for _ in range(m):
    a,b = map(int, input().split())
    if a < minSix:
        minSix = a
    if b < minOne:
        minOne = b

print(min(minOne*n, minSix*(n//6 + 1), minSix*(n//6) + minOne*(n%6)))