import sys
import math
import pygame
import random

def ccw(p1, p2, p3):
    return p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1])

def monotonechain(dots):
    dots.sort(key=lambda x:(x[0],x[1]))
    if len(dots) <=2:
        return dots

    lower = []
    for d in dots:
        while len(lower) >= 2 and ccw(lower[-2], lower[-1], d) <= 0:
            lower.pop()
        lower.append(d)

    upper = []
    for d in reversed(dots):
        while len(upper) >= 2 and ccw(upper[-2], upper[-1], d) <= 0:
            upper.pop()
        upper.append(d)
    return lower[:-1] + upper[:-1]

def getDistSquared(d1, d2):
    return (d1[0] - d2[0])**2 + (d1[1] - d2[1])**2

def calc(d1,d2,d3):
    return getDistSquared(d1, d2) + getDistSquared(d2, d3) + getDistSquared(d1, d3)

def dotToScreenDot(a):
    return int(round(a[0])), int(round(SCREEN_SIZE[1]-a[1]))

def drawPoly(dots, color, screen, width):
    for i in range(len(dots)):
        pygame.draw.line(screen, color, dotToScreenDot(dots[i-1]), dotToScreenDot(dots[i]), width)

def drawDot(x,y,color,size):
    pygame.draw.circle(screen, color, dotToScreenDot((x,y)), size)

if __name__ == '__main__':
    SCREEN_SIZE = [1920, 1080]
    n = int(input("점 개수: "))
    LOOP_COUNT = int(input("반복 횟수: "))
    ratio = float(input("ratio 시작 값:"))
    ratioChange = float(input("ratio 줄이는 값 (1보다 작아야함. 0.995 추천)"))
    FPS = int(input("FPS: "))
    dots = [[random.randint(100, SCREEN_SIZE[1]-100), random.randint(100, SCREEN_SIZE[1]-100)] for _ in range(n)]
    RED = (255, 0, 0)
    BLACK = (0, 0, 0)
    BLUE = (0, 0, 255)
    WHITE = (255, 255, 255)
    pygame.init()
    screen = pygame.display.set_mode(SCREEN_SIZE, pygame.FULLSCREEN)
    clock = pygame.time.Clock()
    important = monotonechain(dots)
    font = pygame.font.Font(None, 40)
    
    xSum = 0
    ySum = 0
    for i in range(n):
        xSum += dots[i][0]
        ySum += dots[i][1]
    x = xSum/n
    y = ySum/n
    x = random.randint(0, 1920)
    y = random.randint(0, 1080)
    for nowLoopCount in range(LOOP_COUNT):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
        screen.fill(WHITE)
        drawPoly(important, RED, screen, 5)
        for i in range(n):
            drawDot(dots[i][0], dots[i][1], BLACK, 3)
        maxIn = 0
        maxVal = (x - important[0][0])**2 + (y - important[0][1])**2
        for i in range(len(important)):
            if (tmp:= (x - important[i][0])**2 + (y - important[i][1])**2) > maxVal:
                maxVal = tmp
                maxIn = i
        x += (important[maxIn][0] - x)*ratio
        y += (important[maxIn][1] - y)*ratio
        drawDot(x,y, BLUE, 3)
        pygame.draw.circle(screen, BLUE, dotToScreenDot((x,y)), int(round(math.sqrt(maxVal))), 5)
        pygame.draw.line(screen, BLUE, dotToScreenDot((x,y)), dotToScreenDot(important[maxIn]), 2)
        ratio *= ratioChange
        screen.blit(font.render(f'{n=}', True, BLACK), (0, 0))
        screen.blit(font.render(f'{FPS=}', True, BLACK), (0, 30))
        screen.blit(font.render(f'{nowLoopCount=}', True, BLACK), (0, 60))
        screen.blit(font.render(f'{ratio=}', True, BLACK), (0, 90))
        screen.blit(font.render(f'{round(x,3)=} {round(y,3)=}', True, BLACK), (0, 120))
        screen.blit(font.render(f'{round(math.sqrt(maxVal),3)=}', True, BLACK), (0, 150))
        pygame.display.flip()
        clock.tick(FPS)
    print(f'{x=} {y=}')
pygame.quit()
