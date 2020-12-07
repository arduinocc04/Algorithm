#include <cstdio>

int T, k, use[5000000], tmp;
int main() {
    scanf("%d", &T);
    int j = 1;
    int k = 1;
    for(int i = 0; i < 5000000; i++) {
        if(i == k) {
            use[i] = 0;
            j++;
            k += j;
        }
        else {
            use[i] = k-i;
        }
    }
    while(T--)  {
        scanf("%d", &k);
        if(k%2 || k > 4002000)  {
            printf("-1\n");
        }
        else if(k <= 4000) {
            printf("%d\n", k/2);
            for(int i = 0; i < k/2; i++) {
                printf("1 ");
            }
            printf("\n");
        }
        else {
            k/= 2;
            
        }
    }
    return 0;
}