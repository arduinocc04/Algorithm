import math
for _ in range(int(input())):
    x1, y1, r1, x2, y2, r2 = [int(i) for i in input().split()]
    circleDistance = math.sqrt((x1-x2)**2 + (y1-y2)**2)
    if x1 == x2 and y1 == y2 and r1 == r2:
        print(-1)
    elif circleDistance < abs(r1-r2) or circleDistance > r1 + r2:
        print(0)
    elif circleDistance == abs(r1-r2) or circleDistance == r1+r2:
        print(1)
    else:
        print(2)