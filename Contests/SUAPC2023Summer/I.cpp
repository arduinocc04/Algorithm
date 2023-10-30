#include <cstdio>
#include <utility>
#include <vector>

// https://rebro.kr/107

using ll = long long;
const int MOD = (int)1e9 + 7;

#define MN 1'000'010
ll fac[MN+10], facinv[MN+10], inv[MN+10];
void fac_init() {
	fac[0] = facinv[0] = inv[1] = 1;
	for (int i = 1; i <= MN; i++) {
		inv[i+1] = (MOD - MOD / (i+1)) * inv[MOD%(i+1)] % MOD;
		fac[i] = fac[i - 1] * i % MOD;
		facinv[i] = facinv[i-1]* inv[i] % MOD;
	}
}
ll C(ll n, ll r) {
	return ((fac[n] * facinv[r]) % MOD) * facinv[n - r] % MOD;
}

// https://rebro.kr/107

 // fast nCr 전처리..

int n, m, k, p[25], ans;
std::pair<int, int> bombs[25];
std::vector<int> tmp;

int find(int n) {
    if(n == p[n]) return n;
    return p[n] = find(p[n]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    p[y] = x;
}

long long calc(int right, int down) {
    return C(right + down, down);
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < 25; i++) p[i] = i;
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &bombs[i].first, &bombs[i].second);
    }
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            if(bombs[i].first <= bombs[j].first && bombs[i].second <= bombs[j].second) {
                merge(i, j);
            }
        }
    }
    fac_init();
    ans = calc(n, m);
    for(int i = 0; i < 25; i++) {
        tmp.clear();
        for(int j = 0; j < 25; j++) {
            if(p[j] == i) tmp.push_back(j);
        }
        
    }

}