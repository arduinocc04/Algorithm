import sys
n,m = map(int, sys.stdin.readline().split())
s = [int(i) for i in sys.stdin.readline().split()]

lo = 0
hi = 0
s_ = s[0]
cnt = 0
flag = False
while lo != n:
    while s_ < m:
        if hi > n:
            flag = True
            break
        hi += 1
        s_ += s[hi]
    if flag: break
    while s_ > m:
        lo += 1
        s_ -= s[lo-1]
    if s_ == m:
        cnt += 1
        hi += 1
print(cnt)