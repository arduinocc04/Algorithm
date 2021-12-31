import sys
input = sys.stdin.readline
print = sys.stdout.write
isPrime[]
for _ in range(int(input())):
    n = int(input())
    m = n-1
    if m % 2 == 1:
        print(f'{(m-1)//2} {(m-1)//2 + 1} 1\n')
    else:
        for 