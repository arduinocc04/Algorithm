#include <cstdio>
#include <vector>
#include <queue>

std::vector<int> graph[32010];
int n, m, a, b, indegree[32010], ans[32010];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        indegree[b]++;
    }
    std::queue <int> queue;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) queue.push(i);
    }
    for(int i = 1; i <= n; i++) {
        ans[i] = queue.front();
        queue.pop();
        for(int next:graph[ans[i]]) if(--indegree[next] == 0) queue.push(next);
    }
    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
}