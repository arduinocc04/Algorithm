#include <cstdio>
#include <vector>
#include <queue>

int T, n, k, x, y, w, d[1010], price, a;
std::vector<int> graph[1010];
std::queue<int> queue;
bool calced[1010];

int max(int x, int y) {
    return (x>y)?x:y;
}


int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++) scanf("%d", &d[i]);
        for(int i = 0; i < 1010; i++) graph[i].clear();
        for(int i = 0; i < 1010; i++) calced[i] = false;
        for(int i = 0; i < queue.size(); i++) queue.pop();
        for(int i = 0; i < k; i++) {
            scanf("%d %d", &x, &y);
            graph[y].push_back(x);
        }
        scanf("%d", &w);
        price = d[w-1];
        queue.push(w);
        while(queue.size() != 0) {
            a = 0;w 
            for(int i = 0; i < queue.size(); i++) {
                a = max(a, queue.front());
                queue.pop();

            }
        }
        printf("%d\n", price);
    }
}