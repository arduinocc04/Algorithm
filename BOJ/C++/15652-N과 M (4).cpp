#include <cstdio>
#include <vector>

int n, m;

void calc(int prev, std::vector<int> things) {
    things.push_back(prev);
    if(things.size() == m) {
        for(int i = 0; i < m; i++) printf("%d ", things[i]);
        printf("\n");
        return;
    }
    for(int i = prev; i <= n; i++) calc(i, things);
}

int main() {
    scanf("%d %d", &n, &m);
    std::vector<int> ans;
    for(int i = 1; i <= n; i++) calc(i, ans);
}