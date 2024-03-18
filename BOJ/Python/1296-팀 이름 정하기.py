def calc(a:str, ly, oy, vy, ey) -> int:
    l = a.count('L') + ly
    o = a.count('O') + oy
    v = a.count('V') + vy
    e = a.count('E') + ey
    return ( (l+o) % 100) * ((l + v)%100)*((l+e)%100)*((o+v)%100)*((o+e)%100)*((v+e)%100) % 100

a = input()
ly = a.count('L')
oy = a.count('O')
vy = a.count('V')
ey = a.count('E')
m = -1
mm = -1
n = int(input())
for _ in range(n):
    a = input()
    t = calc(a, ly, oy, vy, ey)
    if t > mm:
        mm = t
        m = a
    elif t == mm:
        aaaaaaa = sorted([a, m])
        m = aaaaaaa[0]
print(m)
