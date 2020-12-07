#include<cstdio>
#include<deque>
#include<string.h>
using namespace std;
int main() {
    int n, param;
    scanf("%d", &n);
    std::deque<int> queue;
    char cmd[15];
    while(n--) {
        scanf("%s", &cmd);
        if(strlen(cmd) == 4) {
            if(cmd[0] == 's') {
                printf("%d\n", queue.size());
            }
            else {
                if(queue.size()) {
                    printf("%d\n", queue.back());
                }
                else{
                    printf("-1\n");
                }
            }
        }
        else if(strlen(cmd) == 5) {
            if(cmd[0] == 'e') {
                printf("%d\n", queue.empty());
            }
            else {
                if(queue.size()) {
                    printf("%d\n", queue.front());
                }
                else{
                    printf("-1\n");
                }
            }
        }
        else if(strlen(cmd) == 8) {
            if(queue.size()) {
                printf("%d\n", queue.back());
                queue.pop_back();
            }
            else {
                printf("-1\n");
            }
        }
        else if(strlen(cmd) == 9) {
            if(cmd[1] == 'o') {
                if(queue.size()) {
                    printf("%d\n", queue.front());
                    queue.pop_front();
                }
                else{
                    printf("-1\n");
                }
            }
            else {
                scanf("%d", &param);
                queue.push_back(param);
            }
        }
        else {
            scanf("%d", &param);
            queue.push_front(param);
        }
    }
}