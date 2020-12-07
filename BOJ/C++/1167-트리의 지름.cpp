#include <cstdio>
#include <vector>

int v;

std::vector <std::pair <int, int>> graph[100001];

int dfs(int n, int s, int prev) {
    if(graph[n].size() == 1 && graph[n][0].first == prev) {
        return s;
    }
    for(int i = 0; i < graph[n].size(); i++) {
        dfs(graph[n][i].first, s + graph[n][i].second, n);
    }
}

int main() {
    scanf("%d", &v);
    int a, b, c;
    for(int i = 0 ; i < v; i++) {
        scanf("%d", &c);
        while(true) {
            scanf("%d %d", &a, &b);
            if(a == -1) {break;}
            graph[c-1].push_back(std::make_pair(a-1,b));
        }
    }
    int r = dfs(0, 0, -1);
    printf("%d", dfs(r, 0, -1));
    return 0;
}