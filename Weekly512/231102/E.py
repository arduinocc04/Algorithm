import math
x_a, x_b= input().split()
x_a = reversed(x_a)
x_b = reversed(x_b)
n_a = []
n_b = []
for i in x_a:
    if ord('0') <= ord(i) <= ord('9'): n_a.append(int(i))
    else:
        n_a.append(ord(i) - ord('a') + 10)
for i in x_b:
    if ord('0') <= ord(i) <= ord('9'): n_b.append(int(i))
    else:
        n_b.append(ord(i) - ord('a') + 10)
#print(n_a, n_b)
def calc(arr, base):
    tmp = 0
    for i in range(len(arr)):
        tmp += arr[i]*int(math.pow(base, i))
    return tmp
cnt = 0
x = -1
a = -1
b = -1
two63 = 2**63
for i in range(max(max(n_a) + 1, 2), 37):
    for j in range(max(max(n_b) + 1, 2), 37):
        if i == j: continue
        if calc(n_a, i) == calc(n_b, j):
            if calc(n_a, i) >= two63: continue
            #print("="*50)
            #print(i, calc(n_a, i), calc(n_b, j), j)
            #print("="*50)
            if cnt == 0:
                cnt = 1
                x = calc(n_a, i)
                a = i
                b = j
            else:
                cnt += 1
if cnt == 0:
    print("Impossible")
elif cnt == 1:
    print(x, a, b)
else:
    print("Multiple")
