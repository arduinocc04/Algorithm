import sys
inputs = []
for i in range(len(sys.stdin)):
    if i != 0 and i%32 == 0:
        inputs.append(tmp)
        tmp = []
    tmp.append(sys.stdin[i])
for i in range(len(inputs)):
    pc = 0
    mem = [False]*(2**5)
    ga = 0
    for line in inputs[i]:
        pc += 1
        if pc > 2**8 -1:
            pc = 0
        cmd, param = int(line[:2]), int(line[2:])
        if cmd == 0:
            mem[param] = ga
        elif cmd == 1:
            ga = mem[param]
        elif cmd == 2:
            if ga == 0:
                pc = param%10
        elif cmd == 4:
            ga -= 1
        elif cmd == 5:
            ga += 1
        elif cmd == 6:
            pc = param%10
        elif cmd == 7:
            tmp = bin(pc)[2:]
            tmp = '0'*(8-len(tmp)) + tmp
            print(tmp)
            break
        