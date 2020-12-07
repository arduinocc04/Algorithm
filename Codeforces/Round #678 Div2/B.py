import sys
input = sys.stdin.readline
#0도 가능

nums = [False, False] + [True]*100010
for i in range(len(nums)):
    if nums[i]:
        for j in range(i, len(nums), i):
            nums[j] = False
        nums[i] = True

for _ in range(int(input())):
    n = int(input())
    if nums[n]:
        ans = [[1]*n for _ in range(n)]
    elif n%2 == 0:
        ans = [[0]*n for _ in range(n)]
        for i in range(n):
            ans[i][i] = 1
        for i in range(n):
            ans[n-i-1][i] = 1
    else:
        ans = [[0]*n for _ in range(n)]
        for i in range(n):
            ans[i][i] = 1
        for i in range(n):
            ans[n-i-1][i] = 1
        ans[n//2][n//2] = 0
        ans[n//2][0] = 1
        ans[0][n//2] = 1
        ans[n//2][-1] = 1
        ans[-1][n//2] = 1
    for i in ans:
        print(*i)