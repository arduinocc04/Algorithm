a, b = map(int, input().split())
n, m = map(int, input().split())

robots = [[i for i in input().split()] for _ in range(n)]
for i in range(n):
    if robots[i][2] == 'N': robots[i][2] = 0
    if robots[i][2] == 'E': robots[i][2] = 1
    if robots[i][2] == 'S': robots[i][2] = 2
    if robots[i][2] == 'W': robots[i][2] = 3
    robots[i][0] = int(robots[i][0])
    robots[i][1] = int(robots[i][1])

flag = False
for _ in range(m):
    robot_id, cmd, repeat = input().split()
    robot_id = int(robot_id) - 1
    repeat = int(repeat)
    if cmd == 'L':
        robots[robot_id][2] += 3*repeat
        robots[robot_id][2] %= 4
    elif cmd == 'R':
        robots[robot_id][2] += repeat
        robots[robot_id][2] %= 4
    else:
        for i in range(repeat):
            x = robots[robot_id][0]
            y = robots[robot_id][1]
            if robots[robot_id][2] == 0:
                y += 1
            elif robots[robot_id][2] == 1:
                x += 1
            elif robots[robot_id][2] == 2:
                y -= 1
            else:
                x -= 1
            if x <= 0 or x > a or y <= 0 or y > b:
                print(f"Robot {robot_id + 1} crashes into the wall")
                flag = True
                break
            for j in range(n):
                if j == robot_id: continue
                if x == robots[j][0] and y == robots[j][1]:
                    print(f"Robot {robot_id + 1} crashes into robot {j + 1}")
                    flag = True
                    break
            if flag: break
            robots[robot_id][0] = x
            robots[robot_id][1] = y
    if flag: break

if not flag:
    print("OK")
