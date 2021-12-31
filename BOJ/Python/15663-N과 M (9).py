import sys
from copy import deepcopy
input = sys.stdin.readline

def calc(prev, things, nums):
    global ans, m
    things.append(nums[prev])
    del nums[prev]
    if len(things) == m:
        tmp = ""
        for i in things:
            tmp += str(i) + " "
        tmp.rstrip()
        ans.add(tmp)
        return
    for i in range(len(nums)):
        calc(i, deepcopy(things), deepcopy(nums))

n, m = map(int, input().split())
a = [int(i) for i in input().split()]
ans = set()
for i in range(len(a)): calc(i, [], deepcopy(a))
ans = sorted(list(ans))
for i in ans:
    print(i)