#include <cstdio>
#include <deque>

int n, k, T;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &k);
        std::deque<int> queue;
        for(int i = 1; i < n; i++) {
            queue.push_back(i+1);
        }
        int tmp;
        while(queue.size() != 2) {
            for(int i = 0; i < k-1; i++) {
                tmp = queue.front();
                queue.pop_front();
                queue.push_back(tmp);
            }
            queue.pop_front();
        }
        int a = queue.front(), b = queue.back();
        if (a > b) {
            tmp = b;
            b = a;
            a = tmp;
        }
        printf("%d %d\n", a, b);
    }
}