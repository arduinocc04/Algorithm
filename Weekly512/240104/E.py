s, p = map(int, input().split())
dna = input()
target = [int(i) for i in input().split()]
psum = [[0]*4 for _ in range(s + 1)]
for i in range(s):
    for j in range(4):
        psum[i + 1][j] = psum[i][j]
    if dna[i] == 'A':
        psum[i + 1][0] += 1
    elif dna[i] == 'C':
        psum[i + 1][1] += 1
    elif dna[i] == 'G':
        psum[i + 1][2] += 1
    elif dna[i] == 'T':
        psum[i + 1][3] += 1

def calc(a):
    for i in range(4):
        if a[i] < target[i]:
            return False
    return True
cnt = 0
tmp = [0]*4
for i in range(s - p + 1):
    for j in range(4):
        tmp[j] = psum[i + p][j] - psum[i][j]
    cnt += calc(tmp)
print(cnt)
