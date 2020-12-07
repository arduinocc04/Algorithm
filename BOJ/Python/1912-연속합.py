_ = int(input())
a = list(map(int, input().split()))
memo = [a[0]]
for i in range(len(a)-1):
    memo.append(max(memo[-1] + a[i+1], a[i+1]))
print(max(memo))