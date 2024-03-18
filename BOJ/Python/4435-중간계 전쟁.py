a = [1, 2, 3, 3, 4, 10]
b = [1, 2, 2, 2, 3, 5, 10]
def dot(a, b):
    ans = 0
    for i in range(len(a)):
        ans += a[i]*b[i]
    return ans
for zz in range(1, int(input() + 1)):
    c = [int(i) for i in input().split()]
    d = [int(i) for i in input().split()]
    cs = dot(a, c)
    ds = dot(b, d)
    if cs > ds:
        print(f"Battle {zz}: Evil eradicates all trace of Good")
    elif cs < ds:
        print(f"Battle {zz}: Good triumphs over Evil")
    else:
        print(f"Battle {zz}: No victor on this battle field")
