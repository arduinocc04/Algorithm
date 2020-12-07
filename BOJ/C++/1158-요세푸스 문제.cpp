#include <cstdio>
#include <queue>

int n, k, res[5010], tmp, i;
std::queue<int> queue;

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i < n+1; i++) queue.push(i);
    i = 0;
    printf("<");
    while(queue.size() > 0) {
        for(int i = 0; i < k-1; i++) {
            tmp = queue.front();
            queue.pop();
            queue.push(tmp);
        }
        printf("%d", queue.front());
        queue.pop();
        if(queue.size() != 0) printf(", ");
    }
    printf(">");
}