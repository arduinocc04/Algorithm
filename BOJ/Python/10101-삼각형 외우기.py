a = []
for i in range(3):
    a.append(int(input()))
if a[0] + a[1] + a[2] == 180:
    if a[0]^a[1]^a[2] == 60:
        print('Equilateral')
    else:
        b = False
        for i in range(3):
            if a[i-1]^a[i] == 0:
                b = True
                break

        if b:
            print('Isosceles')
        else:
            print('Scalene')

else:
    print('Error')
