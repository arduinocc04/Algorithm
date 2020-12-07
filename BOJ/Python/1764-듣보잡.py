import sys
n,m = map(int, input().split())
a = set()
for i in range(n):
    a.add(sys.stdin.readline().replace('\n', ''))
result = []
for i in range(m):
    b = sys.stdin.readline().replace('\n', '')
    if b in a:
        result.append(b)
result.sort()
print(len(result))
for i in result:
    sys.stdout.write(i+'\n')