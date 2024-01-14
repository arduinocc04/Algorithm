n = int(input())
ans = 0
for i in range(1, 2*n + 1):
    if i % n == i // n:
        ans += i
print(ans)
