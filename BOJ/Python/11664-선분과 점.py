import math

ax,ay,az, bx, by, bz, cx, cy, cz = map(int, input().split())

def getDistSquared(p1,p2):
    return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2 + (p1[2] - p2[2])**2

def ternarySearch(xStart, xEnd, yStart, yEnd, zStart, zEnd):
    while True:
        xLeft = (xStart+xEnd)//3
        xRight = 2*(xStart+xEnd)//3
        yLeft = (yStart+yEnd)//3
        yRight = 2*(yStart+yEnd)//3
        zLeft = (zStart+zEnd)//3
        zRight = 2*(zStart+zEnd)//3
        if getDistSquared((xLeft, yLeft, zRight), (cx, cy, cz)) > getDistSquared((xRight, yRight, zRight), (cx, cy, cz)):
            xStart = xLeft
            yStart = yLeft
            zStart = zLeft
        if getDistSquared((xLeft, yLeft, zRight), (cx, cy, cz)) < getDistSquared((xRight, yRight, zRight), (cx, cy, cz)):
            xEnd = xRight
            yEnd = yRight
            zEnd = zRight
        else:
            return math.sqrt(getDistSquared((xLeft, yLeft, zRight), (cx, cy, cz)))
print(ternarySearch(ax, bx, ay, by, az, bz))