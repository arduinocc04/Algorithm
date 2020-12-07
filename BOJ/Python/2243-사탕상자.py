import sys
input = sys.stdin.readline
n = int(input())
candys = [0]*1000010
for _ in range(n):
    a = [int(i) for i in input().split()]
    if a[0] == 1:
        i = 0
        for j in range(len(candys)):
            if candys[j] > 0:
                i += 1
                if i == a[1]-1:  break
        candys[i] -= 1
        print(i+1)

    else:
        candys[a[1]-1] += a[2]
