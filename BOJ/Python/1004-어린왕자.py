for x in range(int(input())):
    a = [int(i) for i in input().split()]
    startPos = (a[0], a[1])
    endPos = (a[2], a[3])  
    count = 0
    for _ in range(int(input())):
        planet = [int(i) for i in input().split()]
        distance = (startPos[0] - planet[0])**2 + (startPos[1] - planet[1])**2
        distance2 = (endPos[0] - planet[0])**2 + (endPos[1] - planet[1])**2
        count += (planet[2]**2 > distance) ^ (planet[2]**2 > distance2)
    print(count)