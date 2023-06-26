#include <cstdio>

int T, n, d;
char num[200'010];
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &d);
        scanf(" %s", num);
        bool flag = false;
        for(int i = 0; i < n; i++) {
            if(num[i] - '0' < d) {
                flag = true;
                if(i == 0) {
                    printf("%d", d);
                    printf("%s\n", num);
                }
                else {
                    for(int j = 0; j <= i -1; j++) printf("%c", num[j]);
                    printf("%d", d);
                    for(int j = i; j < n; j++) printf("%c", num[j]);
                    printf("\n");
                }
                break;
            }
        }
        if(!flag) printf("%s%d\n", num, d);
    }
    return 0;
}
