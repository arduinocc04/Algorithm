scores = [sum([int(i) for i in input().split()]) for _ in range(5)]

m = 0
for i in range(5):
    if scores[i] > scores[m]:
        m = i
print(m + 1, scores[m])
