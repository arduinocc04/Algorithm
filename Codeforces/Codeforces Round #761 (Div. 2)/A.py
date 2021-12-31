import sys
input = sys.stdin.readline
print = sys.stdout.write
def change(s):
    if inputs[0]*inputs[1]*inputs[2] == 0: return 'abc'
    if s != 'abc':
        return 'abc'
    else:
        return 'acb'
for _ in range(int(input())):
    ans = ""
    s = input().rstrip()
    inputs=[0 for i in range(30)]
    for i in s:
        inputs[ord(i) - ord('a')] += 1
    t = input().rstrip()
    t = change(t)
    for i in t:
        ans += inputs[ord(i) - ord('a')]*i
        inputs[ord(i) - ord('a')] = 0
    for i in range(30):
        if inputs[i] != 0:
            ans += inputs[i]*chr(i+ord('a'))
    print(ans + '\n')
