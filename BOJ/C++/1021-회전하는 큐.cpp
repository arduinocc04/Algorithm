#include <cstdio>
#include <deque>

int n, m, target[60], l, r, tmp, cnt;
std::deque<int> queue;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) queue.push_back(i);
    for(int i = 0; i < m; i++) scanf("%d", &target[i]);
    for(int i = 0; i < m; i++) {
        l = 0, r = 0;
        for(int j = 0; j < queue.size(); j++) {
            if(queue[j] == target[i]) break;
            l++;
        }
        for(int j = queue.size() - 1; j >= 0; j--) {
            r++;
            if(queue[j] == target[i]) break;
        }
        //printf("l %d r %d \n", l, r);
        if(l < r) {
            for(int i = 0; i < l; i++) {
                tmp = queue.front();
                queue.pop_front();
                queue.push_back(tmp);
            }
            queue.pop_front();
            cnt += l;
        }
        else {
            for(int i = 0; i < r; i++) {
                tmp = queue.back();
                queue.pop_back();
                queue.push_front(tmp);
            }
            queue.pop_front();
            cnt += r;
        }
    }
    printf("%d\n", cnt);
}