#include <iostream>

int n;
int a[100'010];

int abs(int x) {
    if(x > 0) return x;
    return -x;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; ++i)
        std::cin >> a[i];

    int l = 0, r = n - 1;
    int ans[2] = {a[0], a[n - 1]};

    while(l < r) {
        if(abs(ans[0] + ans[1]) > abs(a[l] + a[r])) {
            ans[0] = a[l], ans[1] = a[r];
        }

        if(a[l] + a[r] < 0)
            ++l;
        else
            --r;
    }

    std::cout << ans[0] << " " << ans[1] << std::endl;

    return 0;
}
