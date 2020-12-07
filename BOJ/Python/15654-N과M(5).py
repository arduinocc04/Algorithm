def calc(nums:int, depth:int = 0, prevs=''):
    global result
    if depth == len_:
        result.append(prevs[:-1])
        return
    for i in range(len(nums)):
        prev = prevs + str(nums[i]) +' '
        calc(nums[:i] + nums[i+1:], depth + 1, prev)

_, len_ = map(int, input().split())
result = []
calc(sorted([int(i) for i in input().split()]))
for i in result:
    print(i)