#include <cstdio>
#include <vector>
#include <algorithm>

int n, m, a[200'010], u, v, t;
std::vector<std::vector<int>> graph(200'010);
bool used[200'010];

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int dfs(int x, int prev_max, int cnt) {
    if(x == n - 1) {
        return cnt;
    }
    int maxVal = 0;
    for(int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];
        if(used[next] || a[next] < prev_max) continue;
        used[next] = true;
        if(a[next] == prev_max)
            maxVal = max(maxVal, dfs(next, prev_max, cnt));
        else
            maxVal = max(maxVal, dfs(next, a[next], cnt + 1));
        used[next] = false;
    }
    return maxVal;
}

bool cmp(int i, int j) {
    return a[i] < a[j];
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        --u;
        --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0; i < n; i++) std::sort(graph[i].begin(), graph[i].end(), cmp);
    used[0] = true;
    printf("%d", dfs(0, a[0], 1));
    return 0;
}
