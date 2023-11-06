n = int(input())
max_prices = [0]*60
ship_money = [0]*60

for i in range(n):
    p, m = map(int, input().split())
    max_prices[i] = p
    ship_money[i] = m

maxVal = -987654321
maxP = -1

for p in range(1_000_002):
    tmp = 0
    for i in range(n):
        if p <= max_prices[i]:
            tmp += (p - ship_money[i]) if p - ship_money[i] > 0 else 0
    if tmp > maxVal:
        maxP = p
        maxVal = tmp

if maxVal <= 0:
    print(0)
else:
    print(maxP)
