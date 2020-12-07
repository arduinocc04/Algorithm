x = int(input())
result = []

def calc(num, depth = 0):
    global result
    if num == 1:
        result.append(depth)
        return
    if num%3 == 0:
        calc(num//3, depth + 1)
    if num%2 == 0:
        calc(num//2, depth + 1)
    return calc(num -1, depth + 1)

calc(x)
print(min(result))
