n = int(input())
s = input()
cnt = [0]*30
for i in s:
    cnt[ord(i) - ord('A')] += 1

std = "BRONZESILVER"
stda = [0]*30
for i in std:
    stda[ord(i) - ord('A')] += 1

ans = [0]*30
for i in range(30):
    if stda[i] == 0:
        ans[i] = 987654321
        continue
    ans[i] = cnt[i]//stda[i]
print(min(ans))
