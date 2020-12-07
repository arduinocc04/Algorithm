count = 0
for i in range(8):
    a = input()
    if i%2:
        for i in range(1, 8, 2):
            if a[i] == 'F':
                count += 1
    else:
        for i in range(0, 8, 2):
            if a[i] == 'F':
                count += 1
print(count)