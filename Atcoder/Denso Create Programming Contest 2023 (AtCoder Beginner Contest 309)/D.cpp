#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321

int max(int a, int b) {
    if(a < b) return b;
    return a;
}

int n1, n2, m, a, b, t;
std::vector<int> graph[300'010];
int dist[300'010];
bool visited[300'010];
void bfs(int start) {
    std::queue<int> q;
    q.push(start);
    visited[start] = true;
    int d = 0;
    while(!q.empty()) {
        int l = q.size();
        for(int i = 0; i < l; i++) {
            t = q.front();
            q.pop();
            // printf("in: %d\n", t);
            dist[t] = d;
            for(int j = 0; j < graph[t].size(); j++) {
                int next = graph[t][j];
                if(!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        d++;
        // printf("D++ %d\n", d);
    }
}

int main() {
    scanf("%d %d %d", &n1, &n2, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1);
    for(int i = 0; i < 300'010; i++) visited[i] = false;
    bfs(n1 + n2);
    // for(int i = 1; i <= n1 + n2; i++) printf("%d ", dist[i]);
    int res = 0, tmp = 0;
    for(int i = 1; i <= n1; i++) res = max(res, dist[i]);
    for(int i = n1 + 1; i <= n1 + n2; i++) tmp = max(dist[i], tmp);
    printf("%d", tmp + res + 1);
    return 0;
}
