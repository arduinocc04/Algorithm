n = int(input())
balls = input()
print(min((balls[:n//2+1].count(balls[-1]), balls[n//2+1:].count(balls[0]))))