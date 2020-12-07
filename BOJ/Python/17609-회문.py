for _ in range(int(input())):
    string = input()
    count = 0
    for i in range(len(string)//2):
        if string[i] != string[-1-i]:
            count += 1
        if count > 1:
            break
    if count == 0:
        print(0)
    else:
        for i in range(len(string)):
            a = string[:i] + string[i+1:]
            count1 = 0
            for i in range(len(a)//2):
                if a[i] != a[-1-i]:
                    count1 += 1
                if count1 > 1:
                    break
            if count1 == 0:
                break
        if count1 == 0:
            print(1)
        else:
            print(2)