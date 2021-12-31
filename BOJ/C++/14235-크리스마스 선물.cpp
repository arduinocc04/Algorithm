#include <cstdio>
#include <queue>
std::priority_queue<int, std::vector<int>, std::less<int>> pq;
int n, a, tmp;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        if(a == 0) {
            if(pq.size() > 0) {
                printf("%d\n", pq.top());
                pq.pop();
            }
            else printf("-1\n");
        }
        else {
            for(int j = 0; j < a; j++) {
                scanf("%d", &tmp);
                pq.push(tmp);
            }
        }
    }
    return 0;
}