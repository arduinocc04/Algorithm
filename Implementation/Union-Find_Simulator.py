import pygame

def find(n):
    if p[n] == n:  return n
    return find(p[n])

def beautifulFind(n):
    return p[n]

def optimizedFind(n):
    if p[n] == n:  return n
    p[n] = optimizedFind(p[n])
    return p[n]

def union(n1,n2):
    global p
    n1 = find(n1)
    n2 = find(n2)
    if n1 < n2:
        p[n2] = n1
    else:
        p[n1] = n2

def getDistSquared(p1,p2):
    return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2

def dotToScreenDot(a):
    return a[0], SCREEN_SIZE[1]-a[1]

def drawNode(nodeN, color):
    pygame.draw.circle(screen, color, dotToScreenDot(nodes[nodeN]), NODE_RADIUS, 3)
    screen.blit(font.render(f'#{nodeN}', True, color), dotToScreenDot((nodes[nodeN][0] - 5, nodes[nodeN][1] + 5)))

def drawSegBetweenNode(nodeN, nodeJ, color):
    pygame.draw.line(screen, color, dotToScreenDot(nodes[nodeN]),dotToScreenDot(nodes[nodeN]), 3)

def dfs(n, pCoordi, ndNum, depth = 0):
    screen.blit(infoFont.render(f'#{ndNum}', True, BLACK), n)
    pygame.draw.line(screen, RED, n, pCoordi, 3)
    if not ndNum in graph:
        return
    for i in range(len(graph[ndNum])):
        if graph[ndNum][i] != ndNum:
            dfs((n[0] - (len(graph[ndNum])//2 - i)*(100), (depth+1)*100), n, graph[ndNum][i], depth+1)

RED = (255, 0, 0)
BLACK = (0, 0, 0)
BLUE = (0, 0, 255)
WHITE = (255, 255, 255)
SCREEN_SIZE = [1920, 1080]
pygame.init()
flag = int(input("경로압축을 원하십니까? 원하면 1, 아니면 0, 예쁜그래프 원하면 2 >>>"))
screen = pygame.display.set_mode(SCREEN_SIZE, pygame.FULLSCREEN)
done = False
mode = 0#Node Make Mode

nodeCount = 0
nodes = []
p = []
NODE_RADIUS = 20
clickedNode = None
font = pygame.font.Font(None, 30)
infoFont = pygame.font.Font(None, 40)
clock = pygame.time.Clock()
FPS = 60
if flag == 1:
    find = optimizedFind
elif flag == 2:
    find = beautifulFind
while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
                done = True
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_n:
                mode = 0
            elif event.key == pygame.K_u:
                mode = 1# union mode
            elif event.key == pygame.K_ESCAPE:
                done = True
        if event.type == pygame.MOUSEBUTTONDOWN:
            mouseX, mouseY = pygame.mouse.get_pos()
            mouseX, mouseY = dotToScreenDot((mouseX, mouseY))
            if mode == 0:
                p.append(nodeCount)
                nodes.append((int(round(mouseX)), int(round(mouseY))))
                nodeCount += 1
            elif mode == 1:
                for i in range(nodeCount):
                    if getDistSquared((mouseX, mouseY), nodes[i]) <= NODE_RADIUS**2:
                        if clickedNode and i != clickedNode:
                            union(clickedNode, i)
                            clickedNode = None
                        else:
                            clickedNode = i
    screen.fill(WHITE)
    screen.blit(font.render(f'{mode=}', True, BLACK), (SCREEN_SIZE[0]-100, 100))
    for i in range(nodeCount):
        drawNode(i, BLACK)
    if clickedNode:
        drawNode(clickedNode, RED)
    for i in range(nodeCount):
        for j in range(nodeCount):
            if p[i] == p[j]:
                drawSegBetweenNode(i, j, RED)
    graph = {}
    for i in range(nodeCount):
        parentNode = find(i)
        tmp = [i]
        node = i
        while node != parentNode:
            node = p[node]
            tmp.append(node)
        tmp = list(reversed(tmp))
        for i in range(len(tmp)-1):
            if tmp[i] in graph:
                if not tmp[i+1] in graph[tmp[i]]:
                    graph[tmp[i]].append(tmp[i+1])
            else:
                graph[tmp[i]] = [tmp[i+1]]
        if not tmp[0] in graph:
            graph[tmp[0]] = [tmp[0]]
    toFind = []
    for i in range(nodeCount):
        if find(i) == i:
            toFind.append(i)
    for i in range(len(toFind)):
        if toFind[i] in graph:
            tmp = ((i+1)*SCREEN_SIZE[0]//(len(graph)+1), 30)
            dfs(tmp, tmp, toFind[i])
    pygame.display.flip()
    clock.tick(FPS)

print(graph)
print(p)
pygame.quit()