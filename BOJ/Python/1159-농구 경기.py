n = int(input())
cnt = [0]*(ord('z') - ord('a') + 1)
for _ in range(n):
    cnt[ord(input()[0]) - ord('a')] += 1

f = False
for i in range(len(cnt)):
    if cnt[i] >= 5:
        print(chr(i + ord('a')), end='')
        f = True
if not f: print("PREDAJA")
