a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
cnt = [0, 0]
for i in range(10):
    if a[i] > b[i]: cnt[0] += 1
    elif a[i] < b[i]: cnt[1] += 1
if cnt[0] > cnt[1]:
    print("A")
elif cnt[0] < cnt[1]:
    print("B")
else: print("D")
