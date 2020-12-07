#include <iostream>
#include <queue>

int n, k;
bool visited[100000];

int main() {
    std::cin >> n >> k;
    int a, x, cnt;
    std::queue <int> q;
    std::queue <int> nq;
    q.push(n);
    nq.push(0);
    visited[n-1] = true;
    if (n > k) {
        std::cout << n-k << std::endl;
        return 0;
    }
    while(1) {
        a = q.size();
        for(int i = 0; i < a; i++) {
            x = q.front();
            cnt = nq.front();
            nq.pop();
            q.pop();
            if(x == k) {
                std::cout << cnt << std::endl;
                return 0;
            }
            if(x < 100000 && !visited[x]) {
                q.push(x+1);
                nq.push(cnt+1);
                visited[x] = true;
            }
            if(x > 1 && !visited[x-2]) {
                q.push(x-1);
                nq.push(cnt+1);
                visited[x-2] = true;
            }
            if(x <= 50000 && !visited[2*x-1]) {
                q.push(2*x);
                nq.push(cnt+1);
                visited[2*x-1] = true;
            }

        }
    }
}