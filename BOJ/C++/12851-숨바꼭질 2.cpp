#include <cstdio>
#include <deque>
#define max 100000
int n, k, x, cnt, a, b, cntthings, len, y;
bool visited[100010], things[100010];
std::deque<int> queue;

int main() {
    scanf("%d %d", &n, &k);
    cnt = 0;
    queue.push_back(n);
    while(true) {
        len = queue.size();
        for(int i = 0; i < len; i++) {
            x = queue.front();
            queue.pop_front();
            visited[x] = true;
            if(x == k) cntthings++;
            if((x+1 <= max )&& (!visited[x+1])) {
                queue.push_back(x+1);
                //things[x+1] = true;
            }
            if((x-1 >= 0 )&& (!visited[x-1])) {
                queue.push_back(x-1);
                //things[x+1] = true;
            }
            if(((x<<1) <= max )&& (!visited[(x<<1)])) {
                queue.push_back((x<<1));
                //things[x+1] = true;
            }
        }
        //for(int i = 0; i < 100010; i++) visited[i] = things[i];
        if(cntthings > 0) break;
        cnt++;
    }
    printf("%d\n%d\n", cnt, cntthings);
}