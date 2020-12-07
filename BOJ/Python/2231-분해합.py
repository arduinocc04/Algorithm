a = int(input())

for i in range(a):
    val = i
    for k in str(i):
        val += int(k)
    if val == a:
        print(i)
        break
print(0)
