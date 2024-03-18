i = 1
while True:
    a = input()
    if a == '0': break
    r, w, l = map(int, input().split())
    if r**2 < w**2 + l**2:
        print(f"Pizza {i} does not fit on the table.")
    else:
        print(f"Pizza {i} fits on the table.")
    i += 1
