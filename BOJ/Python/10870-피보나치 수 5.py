def fibonaci(num):
    if num == 0:
        return 0
    elif num == 1:
        return 1
    return fibonaci(num-2) + fibonaci(num-1)
num = int(input())
print(fibonaci(num))