inputList = []
for i in range(5):
    inputList.append(int(input()))
def up(num):
    if num > int(num):
        return int(num)+1
    return int(num)
maxDay = max(up(inputList[1]/inputList[3]), up(inputList[2]/inputList[4]))
print(inputList[0]-maxDay)