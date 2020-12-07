a = []
import sys
dict_ = {}
for _ in range(int(input())):
    a = int(sys.stdin.readline())
    if a in dict_:
        dict_[a] += 1
    else:
        dict_[a] = 1
a = [(i,j) for i, j in zip(dict_.keys(), dict_.values())]
a.sort(key=lambda x: x[0])
for i, j in a:
    sys.stdout.write((str(i) + '\n')*j)
