n = input()
a = [int(i) for i in input().split()]
a.sort()
sum_ = 0
for i in range(len(a)):
    sum_ += a[i]*(n-i)
print(sum_)