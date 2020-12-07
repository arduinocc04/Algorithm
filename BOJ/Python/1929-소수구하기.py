import sys
a,b = map(int, input().split())
nums = [False, False]+[True]*9999999
for i in range(len(nums)):
    if nums[i]:
        for k in range(2*i, len(nums), i):
            nums[k] = False

for i in range(a,b+1,1):
    if nums[i]:
        sys.stdout.write(str(i)+'\n')
    