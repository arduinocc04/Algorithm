def fibonacci(n):
    global fibonacciList
    if n == 0:
        fibonacciList[n][0] += 1
    elif n == 1:
        fibonacciList[n][1] += 1
    else:
        fibonacciList[n][0] += fibonacciList[n-2][0] + fibonacciList[n-1][0]
        fibonacciList[n][1] += fibonacciList[n-2][1] + fibonacciList[n-1][1]

fibonacciList = []
for i in range(41):
    fibonacciList.append([0, 0])
    fibonacci(i)
for _ in range(int(input())):
    a = fibonacciList[int(input())]
    print(f'{a[0]} {a[1]}')