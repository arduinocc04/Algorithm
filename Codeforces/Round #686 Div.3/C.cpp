#include <cstdio>
#include <algorithm>

int T, n, as[200010],res, res1; 
std::pair<int, int> cnts[200010];

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            cnts[i].first = 0;
            cnts[i].second = i;
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &as[i]);
            as[i]--;
            if(i == 0 || as[i-1] != as[i])  cnts[as[i]].first++;
        }
        for(int i = 0; i < n; i++) {
            if(cnts[i].first == 0) cnts[i].first = 1234567891;
        }
        std::sort(&cnts[0], &cnts[n]);
        //printf("#1: %d\n", cnts[0].first);
        res = cnts[0].first + 1 - (cnts[0].second == as[0]) - (cnts[0].second == as[n-1]);
        //printf("condition as0 %d asn-1 %d cntsfirst %d cntsecond %d\n", as[0], as[n-1], cnts[0].first, cnts[0].second);
        //printf("res init: %d\n", res);
        for(int i = 1; i < n; i++) {
            if(cnts[i].first == 1234567891) break;
            res = min(res, cnts[i].first - (cnts[i].second == as[0]) - (cnts[i].second == as[n-1]) + 1);
            if(res == 0) break;
        }
        printf("%d\n", res);
    }
}