n, m = map(int, input().split())
baskets = [i for i in range(n + 1)]
for i in range(m):
    j, k = map(int, input().split())
    tmp = baskets[i]
    baskets[i] = baskets[j]
    baskets[j] = tmp
print(*baskets[1:])
