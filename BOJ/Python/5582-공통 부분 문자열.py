import sys
input = sys.stdin.readline

s = input().rstrip()
t = input().rstrip()

if len(s) > len(t):
    s, t = t, s


def possible(length:int) -> bool:
    if length == 0:
        return True

    substrs_of_t = set()
    for i in range(len(t) - length + 1):
        substrs_of_t.add(t[i:i + length])

    for i in range(len(s) - length + 1):
        if s[i:i + length] in substrs_of_t:
            return True
    return False

l, r = 0, len(s) + 1
while l < r:
    mid = (l + r)//2
    if possible(mid):
        l = mid + 1
    else:
        r = mid

print(l - 1)
