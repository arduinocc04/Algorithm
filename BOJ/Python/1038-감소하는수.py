n = int(input())

i = 0
indexes = [1,0]
nums = [0,1,2,3,4,5,6,7,8,9]
if n <10:
    print(n)
elif n>1022:
    print(-1)
else:
    count= 9
    while count<n:
        for k in range(len(indexes)-1):
            if indexes[-k-2] <= indexes[-k-1]:
                indexes[-k-2] += 1
                if k == 0:
                    indexes[-k-1] = 0
                else:
                    indexes[-k-1] = indexes[-k]+1
        i = 0
        if indexes[0] == 10:
            for k in range(len(indexes)):
                indexes[k] = len(indexes)-k-1
            indexes.insert(0,len(indexes))
        for k in range(len(indexes)):
            i +=  nums[indexes[k]]*(10**(len(indexes)-k-1))
        count += 1
        indexes[-1] += 1
    print(i)