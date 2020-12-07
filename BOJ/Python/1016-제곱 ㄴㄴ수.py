import time
a = time.time()
min_, max_ = map(int, input().split())
nums = [True]*1001
nums[0] = False
nums[1] = False
niceNums = []
nA = niceNums.append
for i in range(len(nums)):
    if nums[i]:
        nA(i**2)
        for j in range(2, len(nums)//i):
            nums[j*i] = False
cnt = 0
flags = [True]*(max_ -min_)
for i in range(0, max_ - min_):
    if flags[i]:
        flag = True
        for j in niceNums:
            if i%j == 0:
                for j in range(1, len(nums)//(i+min_)):
                    flags[j*(i+min_)] = False
                break
        cnt += 1
print(f'{time.time()-a=}')
print(cnt)