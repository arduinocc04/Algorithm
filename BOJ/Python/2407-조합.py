n,m = map(int, input().split())
def p(n:int,m:int,cnt:int=0):
    if cnt == m:
        return 1
    else:
        return n*p(n-1,m,cnt+1)
print(p(n,m)//p(m,m))