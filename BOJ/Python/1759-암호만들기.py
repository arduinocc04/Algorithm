import sys
l,c = map(int, input().split())
alpha = sorted([i for i in input().split()])
def calc(n=[], vc=0, prev= -1):
    if len(n) == l:
        if vc and l-vc>1:
            res = ''
            for i in n:
                res += i
            sys.stdout.write(res + '\n')
        return
    for i in range(prev+1, c):
        if not alpha[i] in n:
            calc(n + [alpha[i]], vc+int(alpha[i] in ['a','e','i','o','u']), i)
calc()