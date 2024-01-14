n = int(input())
def f(l, k):
    if l == 0:
        if int(k) <= n:
            return int(k)
        return 4
    if int(k) <= n:
        return max(f(l - 1, k + "4"), max(f(l - 1, k + "7"), int(k)))
    else:
        return max(f(l - 1, k + "4"), f(l - 1, k + "7"))

print(max(f(10, "4"), f(10, "7")))

