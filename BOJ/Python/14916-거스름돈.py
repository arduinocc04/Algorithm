n = int(input())
max_ = n//5
def calc(n, depth=0):
    if n//5 > max_:
        return None
    if n%2 == 0:
        return n//2 - depth
    else:
        return calc(n+5, depth+1)

a = calc(n%5)
if a != None:
    print(max_ + a)
else:
    print(-1)