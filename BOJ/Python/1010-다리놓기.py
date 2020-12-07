def factorial(n):
    if n == 1:
        return 1
    return n*factorial(n-1)

def p(n, r, count = 0):
    if count == r:
        return 1
    return n*p(n-1, r, count+1)

for _ in range(int(input())):
    n,m = [int(i) for i in input().split()]
    print(p(m,n)//factorial(n))