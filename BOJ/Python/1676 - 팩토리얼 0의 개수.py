n = int(input())
prev = 2
if n == 1 or n == 0 or n == 2:
    print(0)
else:
    for i in range(n-2):
        prev = prev*(i+3)
    i = 0
    while True:
        if prev%10 != 0:
            break
        i += 1
        prev //= 10
    print(i)
