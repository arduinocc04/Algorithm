#include <cstdio>
#include <queue>

long long a, b, n, l, cnt;
std::queue<long long> queue;

int main() {
    scanf("%d %d", &a, &b);
    queue.push(a);
    while(true) {
        l = queue.size();
        if(l == 0) {
            printf("-1\n");
            return 0;
        }
        for(int i = 0; i < l; i++) {
            n = queue.front();
            queue.pop();
            if(n == b) {
                printf("%d\n", ++cnt);
                return 0;
            }
            if(2*n <= b) queue.push(2*n);
            if(10*n+1 <= b) queue.push(10*n+1);
        }
        cnt++;
    }
}