while True:
    a = input()
    if a == "#": break
    a = a.lower()
    cnt = [0]*(ord('z') -ord('a') + 1)
    for i in a:
        if ord(i) < ord('a') or ord(i) > ord('z'): continue
        cnt[ord(i) - ord('a')] += 1
    ans = 0
    for j in cnt:
        if j > 0: ans += 1
    print(ans)
