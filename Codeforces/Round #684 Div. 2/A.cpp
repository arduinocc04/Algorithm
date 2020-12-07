#include <cstdio>
#include <cmath>
#include <algorithm>

int T, n, c0, c1, h, res, cnt1, cnt0, tmp;
char s[1010];
using namespace std;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d %d", &n, &c0, &c1, &h);
        cnt1 = 0;
        cnt0 = 0;
        for(int i = 0; i < n; i++) {
            scanf("%c", &s[i]);
            if(s[i]-48) cnt1++;
            else cnt0++;
        }
        printf("%d %d \n", cnt0, cnt1);
        res = 0;
        for(int i = 0; i < n; i++) {
            if(s[i]) res += c1;
            else res += c0;
        }
        if (abs(c0 - c1) > h) {
            if(c0 > c1) res = res + h*cnt0 - c0*cnt0 + c1*cnt0;
            else res = res + h*cnt1 - (c1-c0)*cnt1;
        }
        printf("%d\n", res);
    }
}