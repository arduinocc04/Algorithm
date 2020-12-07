
n,m = map(int, input().split())
map_ = [[int(i) for i in input().split()] for _ in range(n)]
dp = [[0]*m for _ in range(n)]
dp[0][0] = 1
dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]
def dfs(x,y):

print(dp[0][-1])