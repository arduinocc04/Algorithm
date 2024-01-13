n = int(input())
a = [int(i) for i in input().split()]
cnt = [0]*1010
for i in a:
    cnt[i] += 1

s = 0
for i in range(1010):
    if cnt[i] <=2:
        s += cnt[i]
    else:
        s += 2
print(s)
