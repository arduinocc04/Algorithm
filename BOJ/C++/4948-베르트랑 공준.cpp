#include <cstdio>
const int MAX = 123456 *2 + 10;
int n, cnt;
bool prime[MAX];
int main() {
    for(int i = 0; i < MAX; i++) prime[i] = true;
    prime[1] = false;
    prime[0] = false;
    for(int i = 0; i*i < MAX; i++) {
        if(prime[i]) {
            for(int j = i*i; j < MAX; j+= i) {
                prime[j] = false;
            }
        }
    }
    while(true) {
        scanf("%d", &n);
        if(n == 0) break;
        cnt = 0;
        for(int i = n+1; i <= 2*n; i++) {
            if(prime[i]) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}