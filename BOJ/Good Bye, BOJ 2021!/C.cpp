#include <cstdio>
#include <algorithm>
int n, g, k, s[200'010], l[200'010], o[200'010], cnt;
std::pair<unsigned long long, int> tmp[200'010];
unsigned long long sum;

long long max(long long a, long long b) {
    return (a>b)?a:b;
}

int calc(unsigned long long t) {
    for(int i = 0; i < n; i++) {
        tmp[i].first = s[i]*max(1, t -l[i]);
        tmp[i].second = i;
    }
    std::sort(tmp, tmp+n);
    cnt = 0;
    sum = 0;
    for(int i = n-1; i >= 0; i--) {
        if(o[tmp[i].second] && cnt < k) {
            cnt++;
            continue;
        }
        sum += tmp[i].first;
        if(tmp[i].first > g || sum > g) return false;
    }
    //printf("%lld\n", sum);
    return true;
}

int main() {
    scanf("%d %d %d", &n, &g, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &s[i], &l[i], &o[i]);
    }
    unsigned long long s = 0;
    unsigned long long mid;
    unsigned long long e =2e9+4;
    while(s +1 < e) {
        mid = (s+e)/2;
        if(calc(mid)) {
            s = mid;
        }
        else {
            e = mid;
        }
    }
    printf("%lld\n", s);
    return 0;
}