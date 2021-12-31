#include <cstdio>
#include <vector>
int T, n, tmp;
bool available[110];
std::vector<std::pair<int, int>> combi[110];
std::vector<int> ans;
int dp[110][110];
int main() {
    scanf("%d", &T);
    while(T--) {
        ans.clear();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) available[i] = true;
        for(int i = 1; i <= n; i++) {
            if(available[i]) ans.push_back(i);
            if(ans.size() >= 2) {
                for(auto j:ans) {
                    tmp = i ^ j;
                    if(tmp <= n) available[tmp] = false;
                }
            }
        }
        printf("%d\n", ans.size());
        for(auto i:ans) printf("%d ", i);
        printf("\n");
    }
}