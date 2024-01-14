n = int(input())
fs = [int(i) for i in input().split()]
s = int(input())
ans = 0
for f in fs:
    ans += s*(f // s + ((f % s) > 0))
print(ans)
