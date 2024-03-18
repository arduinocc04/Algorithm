while True:
    a, b = map(int, input().split())
    if a == b and a == 0:
        break
    if b % a == 0:
        print("factor")
    else if a % b == 0:
        print("multiple")
    else:
        print("neither")

