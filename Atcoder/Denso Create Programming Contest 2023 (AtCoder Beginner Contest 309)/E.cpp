#include <cstdio>
#include <vector>
#include <queue>

std::vector<int> graph[300'010];
int distFrom1[300'010];
int n, m, p, t, call[300'010], x, y;

int max(int a, int b) {
    if(a < b) return b;
    return a;
}

void bfs(int start) {
    std::queue<int> q;
    q.push(start);
    int d = 0;
    while(!q.empty()) {
        int lq = q.size();
        for(int i = 0; i < lq; i++) {
            t = q.front();
            q.pop();
            distFrom1[t] = d;
            for(int j = 0; j < graph[t].size(); j++) {
                    q.push(graph[t][j]);
            }
        }
        d++;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 2; i <= n; i++) {
        scanf("%d", &p);
        graph[p].push_back(i);
    }
    // printf("===\n");
    // for(int i = 1; i <= n; i++) {
    //     printf("%d: ", i);
    //     for(int j = 0; j < graph[i].size(); j++) {
    //         printf("%d ", graph[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        call[x] = max(call[x], y);
    }
    bfs(1);
    for(int i = 1; i <= n; i++) printf("%d ", distFrom1[i]);
    return 0;
}
