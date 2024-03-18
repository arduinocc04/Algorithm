n = int(input())
a = [int(i) for i in input().split()]
need = 0
cnt = 0
for i in a:
    if need == i:
        cnt += 1
        need = (need + 1) %3
print(cnt)
