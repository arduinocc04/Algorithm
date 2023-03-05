#include <cstdio>

int T;
long long n;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%lld", &n);
        if(n % 9 == 0 ||n % 3 == 2) {
            printf("TAK\n");
        }
        else {
            printf("NIE\n");
        }
    }
    return 0;
}