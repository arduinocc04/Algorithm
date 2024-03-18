n = int(input())
s = [0, 0, 0]
cnt = [[0, 0], [0, 0], [0, 0]]
for _ in range(n):
    a = [int(i) for i in input().split()]
    for i in range(3):
        s[i] += a[i]
        if a[i] == 3:
            cnt[i][1] += 1
        elif a[i] == 2:
            cnt[i][0] += 1

s = [(s[0], 1), (s[1], 2), (s[2], 3)]
s.sort(key = lambda x: x[0])
if s[0][0] == s[1][0] or s[1][0] == s[2][0]:
    print(0, s[2][0])
else:
    print(s[2][1], s[2][0])
