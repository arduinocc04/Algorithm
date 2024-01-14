s1, s2, s3 = map(int, input().split())
cnt = [0]*(20 + 20 + 40 + 10)
for i in range(1, s1 + 1):
    for j in range(1, s2 + 1):
        for k in range(1, s3 + 1):
            cnt[i + j + k] += 1
a = max(cnt)
for i in range(len(cnt)):
    if cnt[i] == a:
        print(i)
        break
