#include <cstdio>
#include <vector>

int n, tmp1, tmp2, ans[5010][5010], res;
std::vector <int> graph[5010];
int dist(int node, int depth, int target, int prev) {
    if(node == target) return depth;
    for(auto i: graph[node]) {
        if(i != prev) {
            int tmp = dist(i, depth+1, target, node);
            if(tmp != 0) return tmp;
        }
    }
    return 0;
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }
    res = 0;
    for(int i = 0; i < n+1; i++) {
        for(int j = i+1; j < n+1; j++) {
            ans[i][j] = dist(i, 0, j, -1);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            res += (ans[j][0] + ans[i][0] + ans[i][j])/2;
        }
    }
    printf("%d", res);
}