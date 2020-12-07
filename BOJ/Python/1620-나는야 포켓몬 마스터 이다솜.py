import sys
n,m = map(int, input().split())
dict_ = {}
for i in range(n):
    dict_[sys.stdin.readline().replace('\n','')] = i
result = []
for i in range(m):
    result.append(sys.stdin.readline().replace('\n', ''))
for i in range(len(result)):
    if ord(result[i][0]) < 49 or ord(result[i][0]) > 57:
        result[i] = int(dict_[result[i]]) + 1
dict_ = list(dict_.keys())
for i in range(len(result)):
    if type(result[i]) is str:
        result[i] = dict_[int(result[i])-1]

for i in result:
    sys.stdout.write(f'{i}\n')