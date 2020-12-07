inputs = []
for _ in range(int(input())):
    inputs.append(input())

pattern = ''
for i  in range(len(inputs[0])):
    character = inputs[0][i]
    for k in range(len(inputs)):
        if inputs[0][i] != inputs[k][i]:
            character = '?'
            break
    pattern += character
print(pattern)