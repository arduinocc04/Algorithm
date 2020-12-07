def s(equation):
    a = [int(i) for i in equation.split('+')]
    return sum(a)

equation = input()
a = equation.split('-')
result = s(a[0])
for i in range(len(a)-1):
    result -= s(a[i+1])
print(result)