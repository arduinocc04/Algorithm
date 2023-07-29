#include <cstdio>
#include <vector>

std::vector<int> graph[200'010];
int T, n, t;
bool visited[200'010];
std::vector<int> history;
bool printed;

void dfs(int now) {
    if(printed) return;

    if(visited[now]) {
        int start;
        for(int i = history.size() -1; i >= 0; i--) {
            if(history[i] == now) {
                start = i;
                break;
            }
        }
        printf("%d\n", history.size() - start);
        for(int i = start; i < history.size(); i++) {
            printf("%d ", history[i]);
        }
        printed = true;
        return;
    }

    visited[now] = true;
    for(int i = 0; i < graph[now].size(); i++) {
        history.push_back(now);
        dfs(graph[now][i]);
        history.pop_back();
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        graph[i + 1].push_back(t);
    }
    dfs(1);
}
