x1,y1,x2,y2 = map(int, input().split())
x3,y3,x4,y4 = map(int, input().split())
x = 0
y=0
if x1<=x3<=x2 and x1<=x4<=x2:
    x = x4-x3
elif x3<=x1<=x4 and x3<=x2<=x4:
    x = x2-x1
elif x1<=x3<=x2:
    x = x2-x3
elif x1 <= x4 <= x2:
    x = x4-x1

if y2<=y3<=y1 and y2<=y4 <=y1:
    y = y3-y4
elif y4<=y1<=y3 and y4<=y2<=y3:
    y=y1-y2
elif y2 <= y3 <=  y1:
    y = y3-y2
elif y2 <= y4 <= y1:
    y = y1-y4
print(x*y)
