len_ = int(input())
count = 0
def search(a:str) -> None:
    global count
    if len(a) == len_:
        count += 1
        return
    if a[-1] == '1':
        search(a + '0')
    else:
        search(a + '1')
        search(a + '0')

search('1')
print(count)