#include <cstdio>

int T, n, cnt, prev, minResult;
int calc(int num) {
    int cnt = 0;
    bool flag;
    while(num != 1) {
        flag = false;
        for(int i = 2; i < num; i++) {
            if(num%i == 0 && num != i) {
                num  = i;
                cnt++;
                flag = true;
            } 
        }
        if(!flag) {
            num--;
            cnt++;
        }
    }
    return cnt;
}
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        printf("%d\n", calc(n));
    }
}