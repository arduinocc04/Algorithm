import math
length, heightRatio, widthRatio = [int(i) for i in input().split()]

x = math.sqrt(length**2/(1+(heightRatio/widthRatio)**2))
y = int(x*heightRatio/widthRatio)
print(f'{y} {int(x)}')
