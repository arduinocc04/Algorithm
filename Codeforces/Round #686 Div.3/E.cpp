#include <cstdio>
#include <vector>
int T, n, tmp1, tmp2;
std::vector<int> graph[200010];
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &tmp1, &tmp2);
            graph[tmp1].push_back(tmp2);
            graph[tmp2].push_back(tmp1);
        }
        printf("%d\n", 3*n-1);
    }
}