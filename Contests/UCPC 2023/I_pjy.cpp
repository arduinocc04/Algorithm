#include <iostream>
using namespace std;
typedef long long ll;

ll N, K;
ll min_val, max_val, cur;
ll res;
ll a, b;

ll max(ll a, ll b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	cin >> a;
	for (int i = 1; i < N; i++) {
		cin >> b;
		cur = abs(a - b) - (K * i);
		if (i == 1) {
			min_val = cur;
			max_val = cur;
			continue;
		}
		if (min_val > cur) min_val = cur;
		if (max_val < cur) max_val = cur;
	}
	if (N == 2) {
		cout << max(cur, 0) << "\n";
	} else {
		if (max_val <= 0) {
			cout << 0 << "\n";
		} else {
			cout << max_val - min_val << "\n";
		}
	}
	return 0;
}
