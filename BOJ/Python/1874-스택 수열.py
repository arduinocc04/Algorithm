import sys

n = int(sys.stdin.readline())
sequence = []
for _ in range(n):
    sequence.append(int(sys.stdin.readline()))
stack = []
i = 0
j = 1
res = []
while j <= n+1:
    if len(stack) and stack[-1] == sequence[i]:
        del stack[-1]
        i += 1
        res.append('-\n')
    else:
        stack.append(j)
        j += 1
        res.append('+\n')
del res[-1]
if i == n:
    for i in res:
        sys.stdout.write(i)
else:
    sys.stdout.write('NO')