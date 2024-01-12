a, b = map(int, input().split())
n = a - b
if n > b or n <= 0:
    print("NO")
else:
    print("YES")
    print(n)
    for i in range(n - 1):
        print("aba")
    print("ab"*(b - n + 1) + "a")
