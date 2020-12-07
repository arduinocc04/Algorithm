from collections import deque
import sys
queue = deque()
for _ in range(int(input())):
    a = sys.stdin.readline().split()
    if len(a) == 1:
        if a[0] == 'empty':
            sys.stdout.write(str(int(len(queue)==0)) + '\n')
        elif a[0] == 'size':
            sys.stdout.write(str(len(queue)) + '\n')
        elif len(queue):
            if a[0] == 'front':
                sys.stdout.write(str(queue[0])+'\n')
            elif a[0] == 'back':
                sys.stdout.write(str(queue[-1]) + '\n')
            else:
                sys.stdout.write(str(queue.popleft()) + '\n')
        else:
            sys.stdout.write('-1\n')
    else:
        queue.append(int(a[1]))