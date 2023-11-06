n = int(input())
l = int(input())
c = int(input())

cnt = 0
tmp = c
while tmp > 0:
    tmp -= l
    if tmp <= 0: break
    cnt += 1
    tmp -= 1
if cnt % 13 == 0: cnt -= 1
#print(cnt)
if (n % 13 or cnt % 13) and (n > cnt): print(n//cnt + (1 if n % cnt else 0))
else: print(2*n//cnt + (1 if n % cnt else 0))
