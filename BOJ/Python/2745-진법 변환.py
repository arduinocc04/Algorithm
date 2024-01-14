n, b = input().split()
ans = 0
t = 1
b = int(b)
for i in n[::-1]:
    if ord('0') <= ord(i) <= ord('9'): ans += int(i)*t
    else: ans += (ord(i) - ord('A') + 10)*t
    t *= b
print(ans)
