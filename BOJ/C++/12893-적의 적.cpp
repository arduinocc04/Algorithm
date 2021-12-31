#include <cstdio>
#include <vector>
int n, m, p[2010], tmp1, tmp2, edges[1000010][2];
std::vector<int> graph[2010];
bool flag;
int find(int n) {
    if(n == p[n]) return n;
    return p[n] = find(p[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1), n2 = find(n2);
    if(n1 < n2) p[n2] = n1;
    else p[n1] = n2;
    return;
}

bool isInSameSet(int n1, int n2) {
    return find(n1) == find(n2);
}

int dfs(int n, int target, int prev, int depth=0) {
    if(n == target) {
        return depth;
    }
    for(int i = 0; i < graph[n].size(); i++) {
        if(prev == graph[n][i]) continue;
        return dfs(graph[n][i], target, n, depth+1);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) p[i] = i;
    flag = true;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        tmp1--, tmp2--;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
        edges[i][0] = tmp1, edges[i][1] = tmp2;
    }
    for(int i = 0; i < m; i++) {
        tmp1 = edges[i][0], tmp2 = edges[i][1];
        if(isInSameSet(tmp1, tmp2)) {
            if(dfs(tmp1, tmp2, tmp2) %2 == 0) {
                flag = false;
                break;
            }
        }
        else {
            merge(tmp1, tmp2);
        }
    }
    printf("%d\n", flag);
}