# WITHDRAWL
# 시간초과 난 코드의 시간 복잡도가 거의 O(T * nlg^2 n) 이기 때문에 시간초과 날 코드는 아닌데 파이썬 써서 시간초과남. 그래서 반복문 100-> 50으로 줄이고, 이차원 배열을 쓰지 않고 1차원 배열 두개로 나누어서 사용함.(결론: 상수커팅함)
import sys
input = sys.stdin.readline

def calc(x):
    global r, c, k, n
    tmp = [x*c[i] - r[i] for i in range(n)]
    tmp.sort()
    sum_ = 0
    for i in range(k):
        sum_ += tmp[-i-1]
    return sum_ >= 0

for _ in range(int(input())):
    n,k = map(int, input().split())
    tmp = input().split()
    r = []
    c = []
    rA = r.append
    cA = c.append
    for i in range(len(tmp)):
        if i%2:
            cA(int(tmp[i]))
        else:
            rA(int(tmp[i]))
    
    lo = -1e-9
    hi = 1
    for i in range(50):
        mid = (lo + hi)/2
        if calc(mid):
            hi = mid
        else:
            lo = mid
    print(hi)