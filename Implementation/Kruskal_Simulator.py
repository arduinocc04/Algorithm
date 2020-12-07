import pygame
import random

def find(n):
    if p[n] == n:  return n
    p[n] = find(p[n])
    return p[n]

def union(n1,n2):
    global p
    n1 = find(n1)
    n2 = find(n2)
    if n1 < n2:
        p[n2] = n1
    else:
        p[n1] = n2

def isInSameSet(n1,n2):
    return find(n1) == find(n2)

def getDistSquared(p1,p2):
    return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2

def dotToScreenDot(a):
    return a[0], SCREEN_SIZE[1]-a[1]

def drawNode(nodeN, color):
    pygame.draw.circle(screen, color, dotToScreenDot(nodes[nodeN]), NODE_RADIUS, 3)
    screen.blit(font.render(f'#{nodeN}', True, color), dotToScreenDot((nodes[nodeN][0] - 5, nodes[nodeN][1] + 5)))

def drawEdge(edgeNum, color):
    v,e,w = edges[edgeNum]
    pygame.draw.line(screen, color, dotToScreenDot(nodes[v]),dotToScreenDot(nodes[e]), 3)
    midPoint = (nodes[v][0] + nodes[e][0])//2, (nodes[v][1] + nodes[e][1])//2
    screen.blit(font.render(str(w), True, BLUE), dotToScreenDot(midPoint))

RED = (255, 0, 0)
BLACK = (0, 0, 0)
BLUE = (0, 0, 255)
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)
SCREEN_SIZE = [1920, 1080]
nodeCount = int(input("노드 개수를 입력하세요>>>"))
FPS = int(input("FPS >>>"))
spaceMode = int(input("스페이스로 다음 단계를 진행하시겠습니까? 스페이스 사용하려면 1, 아니면 0>>>"))
b = int(input("간선 생길 확률 결정하는 것. 1보다 커야하고, 낮을수록 확률이 높아짐>>>"))
pygame.init()
screen = pygame.display.set_mode(SCREEN_SIZE, pygame.FULLSCREEN)
done = False

nodes = [[random.randint(0, SCREEN_SIZE[0]), random.randint(0, SCREEN_SIZE[1])] for _ in range(nodeCount)]
p = [i for i in range(nodeCount)]
edges = []
eA = edges.append
for i in range(nodeCount):
    for j in range(i+1, nodeCount):
        if random.randint(0,b) < 3:
            eA([i, j, random.randint(0, 1000)])
edges.sort(key=lambda x: x[2])
NODE_RADIUS = 20
clickedNode = None
font = pygame.font.Font(None, 30)
clock = pygame.time.Clock()
MST = []
if spaceMode:
    goNext = False
else:
    goNext = True
i = 0
while len(MST) < nodeCount-1:
    screen.fill(WHITE)
    for j in range(nodeCount):
        drawNode(j, BLACK)
    for j in range(len(edges)):
        drawEdge(j, BLACK)
    for j in range(len(MST)):
        drawEdge(j, RED)
    drawEdge(i, GREEN)#다음 선택할 것
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
                pygame.quit()
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                pygame.quit()
            if event.key == pygame.K_SPACE and spaceMode:
                goNext = True
    if goNext:
        a,b,w = edges[i]
        if not isInSameSet(a,b):
            MST.append(i)
            union(a,b)
        i += 1
        if spaceMode:
            goNext = False
    pygame.display.flip()
    clock.tick(FPS)
if len(MST) != nodeCount-1:
    print("Can't Make MST")
else:
    print([edges[i] for i in MST])
pygame.quit()