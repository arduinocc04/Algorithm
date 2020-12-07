def calc(nums:int, depth:int = 0, prevs=''):
    global result
    if depth == len_:
        result.append(prevs[:-1])
        return
    for i in range(len(nums)):
        prev = prevs + str(nums[i]) +' '
        calc(nums[:i] + nums[i+1:], depth + 1, prev)

m, len_ = map(int, input().split())
result = []
calc([k+1 for k in range(m)])
for i in result:
    print(i)