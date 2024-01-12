n = int(input())
s = input()
val = s[0]
alphabets = [0]*30
cnt = 1
for i in range(1, n):
    if val == s[i]:
        cnt += 1
    else:
        alphabets[ord(val) - ord('a')] = max(alphabets[ord(val) - ord('a')], cnt)
        cnt = 1
        val = s[i]
alphabets[ord(val) - ord('a')] = max(alphabets[ord(val) - ord('a')], cnt)
print(sum(alphabets))
