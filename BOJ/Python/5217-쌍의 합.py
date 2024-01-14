for _ in range(int(input())):
    n = int(input())
    if n <= 2:
        print(f"Pairs for {n}:")
        continue
    print(f"Pairs for {n}: ", end = '')
    cnt = 0
    for i in range(1, n):
        for j in range(i + 1, n):
            if i + j != n: continue
            if cnt == 0: print(f"{i} {j}", end ='')
            else: print(f", {i} {j}",end='')
            cnt += 1
    print()

