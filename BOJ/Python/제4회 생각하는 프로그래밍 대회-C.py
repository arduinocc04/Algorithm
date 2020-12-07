import sys
input = sys.stdin.readline

def getGcd(a,b):
    while b != 0:
        r = a%b
        a = b
        b = r
    return a

n = int(input())
nums = [[int(i) for i in input().split()] for _ in range(n)]
for i in range(n):
    if (tmp:= getGcd(nums[i][0], nums[i][1])) != 1:
        nums[i][0] //= tmp
        nums[i][1] //= tmp
s = 1
for i in range(n):
    s *= nums[i][1]
gcd = getGcd(nums[0][1], nums[1][1])
for i in range(n-1):
    gcd = max(gcd, getGcd(nums[i+1][1], nums[i][1]))
print(f'1 {s//gcd}')