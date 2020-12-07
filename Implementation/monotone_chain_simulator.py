import pygame
import random
import time
def ccw(p1, p2, p3):
    return p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1])

def dotToScreenDot(a):
    return a[0], SCREEN_SIZE[1]-a[1]

def renderDotAndNum(dotNum, color, width=0):
    pygame.draw.circle(screen, color, dotToScreenDot(dots[dotNum]), 5, width)
    screen.blit(coordiFont.render(f'#{dotNum}', True, BLACK), dotToScreenDot((dots[dotNum][0]+5, dots[dotNum][1])))

def drawConnectedLines(dots, color, screen, width):
    for i in range(len(dots)-1):
        pygame.draw.line(screen, color, dotToScreenDot(dots[i]), dotToScreenDot(dots[i+1]), width)
def update():
    screen.fill(WHITE)

if __name__ == '__main__':
    SCREEN_SIZE = [1920, 1080]
    n = int(input("점 개수: "))
    FPS = int(input("FPS: "))
    delayTime = int(input("점 정렬하기까지 기다릴 초(진짜로 정렬되고 싶은지 보고싶은경우, 안보고 싶으면 0)"))
    dots = [[random.randint(0, SCREEN_SIZE[0]), random.randint(0, SCREEN_SIZE[1])] for _ in range(n)]
    RED = (255, 0, 0)
    BLACK = (0, 0, 0)
    BLUE = (0, 0, 255)
    WHITE = (255, 255, 255)
    pygame.init()
    screen = pygame.display.set_mode(SCREEN_SIZE, pygame.FULLSCREEN)
    clock = pygame.time.Clock()
    font = pygame.font.Font(None, 40)
    coordiFont = pygame.font.Font(None, 15)
    startTime = time.time()
    while True:
        screen.fill(WHITE)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
        for i in range(n):
            renderDotAndNum(i, BLACK)
        pygame.display.flip()
        if time.time() - startTime < delayTime:  continue # 정렬후 변하는 것 보기.
        dots.sort(key=lambda x:(x[0],x[1]))
        break

    lower = []
    for d in dots:
        screen.fill(WHITE)
        for i in range(n):
            renderDotAndNum(i, BLACK)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
        drawConnectedLines(lower+[d], RED, screen, 2)
        while len(lower) >= 2 and ccw(lower[-2], lower[-1], d) <= 0:
            lower.pop()
            screen.fill(WHITE)
            for i in range(n):
                renderDotAndNum(i, BLACK)
            drawConnectedLines(lower, RED, screen, 2)
            pygame.display.flip()
            clock.tick(FPS)
        screen.fill(WHITE)
        for i in range(n):
            renderDotAndNum(i, BLACK)
        lower.append(d)
        drawConnectedLines(lower, RED, screen, 2)
        pygame.display.flip()
        clock.tick(FPS)

    upper = []
    for d in reversed(dots):
        screen.fill(WHITE)
        for i in range(n):
            renderDotAndNum(i, BLACK)
        drawConnectedLines(lower, RED, screen, 2)
        drawConnectedLines(upper+[d], RED, screen, 2)
        while len(upper) >= 2 and ccw(upper[-2], upper[-1], d) <= 0:
            upper.pop()
            screen.fill(WHITE)
            for i in range(n):
                renderDotAndNum(i, BLACK)
            drawConnectedLines(lower, RED, screen, 2)
            drawConnectedLines(upper, RED, screen, 2)
            pygame.display.flip()
            clock.tick(FPS)
        screen.fill(WHITE)
        for i in range(n):
            renderDotAndNum(i, BLACK)
        drawConnectedLines(lower, RED, screen, 2)
        upper.append(d)
        drawConnectedLines(upper, RED, screen, 2)
        pygame.display.flip()
        clock.tick(FPS)
    convexHull = lower[:-1] + upper[:-1]
    startTime = time.time()
    while True:
        screen.fill(WHITE)
        for i in range(n):
            renderDotAndNum(i, BLACK)
        if time.time()-startTime > 10:
            break
        drawConnectedLines(convexHull, RED, screen, 1)
    print(convexHull)
