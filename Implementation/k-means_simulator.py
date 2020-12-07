import pygame
import random


def drawNode(nodeN, color):
    pygame.draw.circle(screen, color, dotToScreenDot(nodes[nodeN]), NODE_RADIUS, 3)
    screen.blit(font.render(f'#{nodeN}', True, color), dotToScreenDot((nodes[nodeN][0] - 5, nodes[nodeN][1] + 5)))

def dotToScreenDot(a):
    return int(round(a[0])), int(round(SCREEN_SIZE[1]-a[1]))

def getDistSquared(p1,p2):
    return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2

def drawSeg(clusterNum, nodeNum, color):
    pygame.draw.line(screen, color, dotToScreenDot(nodes[nodeNum]),dotToScreenDot(clusters[clusterNum]), 3)

RED = (255, 0, 0)
BLACK = (0, 0, 0)
BLUE = (0, 0, 255)
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)
SCREEN_SIZE = [1920, 1080]
nodeCount = int(input("노드 개수를 입력하세요>>>"))
FPS = int(input("FPS >>>"))
clusterCount = int(input("클러스터 개수>>>"))
pygame.init()
screen = pygame.display.set_mode(SCREEN_SIZE, pygame.FULLSCREEN)
font = pygame.font.Font(None, 30)
clock = pygame.time.Clock()
NODE_RADIUS = 20

nodes = [[random.randint(0, SCREEN_SIZE[0]), random.randint(0, SCREEN_SIZE[1])] for _ in range(nodeCount)]
colors = [[random.randint(0, 255), random.randint(0, 255), random.randint(0, 255)] for _ in range(clusterCount)]
clusters = [[random.randint(0, SCREEN_SIZE[0]), random.randint(0, SCREEN_SIZE[1])] for _ in range(clusterCount)]
prevs = [clusters[i][:] for i in range(clusterCount)]
p = [None]*nodeCount
while True:
    s = [[0,0] for _ in range(clusterCount)]
    nodeCnt = [0]*clusterCount
    prevs = [clusters[i][:] for i in range(clusterCount)]
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
                pygame.quit()
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                pygame.quit()
    screen.fill(WHITE)
    for i in range(nodeCount):#O(nk)
        minIndex = 0
        minVal = 121212122222
        for j in range(clusterCount):
            if (tmp:= getDistSquared(nodes[i], clusters[j])) < minVal:
                minVal = tmp
                minIndex = j
        p[i] = minIndex
        s[minIndex][0] += nodes[i][0]
        s[minIndex][1] += nodes[i][1]
        nodeCnt[minIndex] += 1
    flag = True
    minChanged = 1321231
    for i in range(clusterCount):
        x,y = s[i][0]/nodeCnt[i], s[i][1]/nodeCnt[i]
        pygame.draw.circle(screen, colors[i], dotToScreenDot((x,y)), 30, 0)
        clusters[i] = [x,y]
        minChanged = min(minChanged, abs(x-prevs[i][0]) + abs(y-prevs[i][1]))
        if abs(x-prevs[i][0]) + abs(y-prevs[i][1]) > 0.0005:
            flag = False
    if flag:  break
    for i in range(nodeCount):
        drawNode(i, colors[p[i]])
    for i in range(nodeCount):
        drawSeg(p[i], i, colors[p[i]])
    screen.blit(font.render(f'{minChanged=}', True, BLACK), (SCREEN_SIZE[0]-300, 30))
    pygame.display.flip()
    clock.tick(FPS)
pygame.quit()
