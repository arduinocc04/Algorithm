import sys
for l in sys.stdin.readlines():
    a, b = map(int, l.split())
    ans = a + a//b
    a = a % b + a // b
    ans += a // b
    a = a % b + a // b
    ans += a // b
    a = a % b + a // b
    ans += a // b
    print(ans)
