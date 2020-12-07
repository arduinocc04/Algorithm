def mergeSort(start, end, n):
    if start == end:
        tmp[start] = a[start]
        return
    mid = (start + end)//2
    mergeSort(start, mid, n)
    mergeSort(mid+1, end, n)
    merge(start, end, n)

def merge(start, end, n):
    global tmp
    if start == end:
        return [n[start]]
    i = start
    mid = (start+end)//2
    j = mid+1
    k = start
    while i <= mid and j <= end:
        if n[i] < n[j]:
            tmp[k] = n[i]
            i += 1
        else:
            tmp[k] = n[j]
            j += 1
        k += 1
    if i > mid:
        while j <= end:
            tmp[k] = n[j]
            j += 1
            k += 1
    else:
        while i <= mid:
            tmp[k] = n[i]
            i += 1
            k += 1
    for i in range(start, end+1):
        n[i] = tmp[i]
if __name__ == '__main__':
    a = [9,8,7,6,5,4,3,2,1,0]
    tmp = [None]*len(a)
    mergeSort(0, len(a)-1, a)
    print(*a)