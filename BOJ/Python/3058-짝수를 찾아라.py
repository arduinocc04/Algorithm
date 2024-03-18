for _ in range(int(input())):
    a = [int(i) if i % 2 for i in input().split()]
    print(sum(a), min(a))
