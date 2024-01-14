i = 1
while True:
    l, p, v = map(int, input().split())
    if l == p == v == 0: break
    print(f"Case {i}: {l*(v//p) + v % p}")
    i += 1
