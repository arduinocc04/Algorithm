#include <cstdio>
#include <utility>
long long T, n, x[200'010], prev, cnt;

std::pair<long long, long long> calc(long long a, long long b) { // prev, cnt
    if(a <= b)
        return std::make_pair(a, 0);
    if(a % b == 0)
        return std::make_pair(b, a/b - 1);
    return std::make_pair((b + (a%b))/2, a/b);
}

int main() {
    scanf("%lld", &T);
    while(T--) {
        scanf("%lld", &n);
        for(int i = 0; i < n; i++)
            scanf("%lld", &x[i]);
        prev = x[n - 1];
        cnt = 0;
        for(int i = n - 2; i >= 0; i--) {
            std::pair<long long, long long> t = calc(x[i], prev);
            prev = t.first;
            cnt += t.second;
        }
        printf("%lld\n", cnt);
    }
    return 0;
}
