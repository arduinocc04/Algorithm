#include <cstdio>
#include <algorithm>

int T, n, zeroCnt;
std::pair<int, int> a[2010];
int gcd(int a, int b) {
    while (b > 0) {
        int tmp = a;
        a = b;
        b = tmp%b;
    }
    return a;
}

int max(int a, int b) {
    return(a>b)?a:b;
}


int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        zeroCnt = 0;
        for(int i = 0; i < n; i++) scanf("%d", &a[i].second);
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(i != j && gcd(a[i].second, a[j].second*2) > 1) a[i].first++;
            }
        }
        std::sort(a, a + n);
        /*
        printf("a: ");
        for(int i = 0; i < n; i++) {
            printf("%d ", a[i].second);
        }
        printf("\n");
        */
        int ans = 0;
        for(int i = n-1; i >= 0; i--) {
            for(int j = i-1; j >= 0; j--) {
                if(gcd(a[i].second, a[j].second*2) > 1) ans++;
            }
        }
        int ans2 = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(gcd(a[i].second, a[j].second*2) > 1) ans2++;
            }
        }
        printf("%d\n", max(ans, ans2));
    }
    return 0;
}
