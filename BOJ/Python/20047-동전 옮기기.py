# s를 [0,i), (i, j), (j, -1]로 나눈뒤, 그것들을 t에서 탐색한후 사용되지 않은 문자 두개 -> i, j.
import sys
input = sys.stdin.readline
n = int(input())
s = input().rstrip()
t = input().rstrip()
i,j = map(int, input().split())
for i in range(n):
    for j in range(i, n+i):
