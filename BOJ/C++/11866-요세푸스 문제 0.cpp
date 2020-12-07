#include <cstdio>
#include <deque>
#include <vector>

int n, k;

int main() {
    scanf("%d %d", &n, &k);
    std::deque<int> queue;
    std::vector<int> res;
    for(int i = 0; i < n; i++) {
        queue.push_back(i+1);
    }
    int tmp;
    while(queue.size() != 0) {
        for(int i = 0; i < k-1; i++) {
            tmp = queue.front();
            queue.pop_front();
            queue.push_back(tmp);
        }
        res.push_back(queue.front());
        queue.pop_front();
    }
    printf("<");
    for(int i = 0; i < n; i++) {
        if(i != n-1) printf("%d, ", res[i]);
        else printf("%d>", res[i]);
    }
}