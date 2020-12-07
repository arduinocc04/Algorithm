n = int(input())
sizes = [int(i) for i in input().split()]
sizes.sort()
def lowerBound(target, left, right):
    while left < right:
        mid = (left + right)//2
        if sizes[mid] >= target:
            right = mid
        else:
            left = mid + 1
    return right
cnt = 0
for i in range(n):
    a = lowerBound(sizes[i]*0.9, 0, i)
    cnt += i-a
print(cnt)