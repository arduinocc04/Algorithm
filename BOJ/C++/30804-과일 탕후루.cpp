#include <cstdio>
#include <algorithm> // for std::max

int n, psum[200'010][10], max_length, s[200'010];

int get_fruit_count(int l, int r) {
    int cnt = 0;
    if(l == 0) {
        for(int i = 0; i < 10; ++i) {
            if(psum[r][i] > 0) ++cnt;
        }
    }
    else {
        for(int i = 0; i < 10; ++i) {
            if(psum[r][i] - psum[l - 1][i] > 0) ++cnt;
        }
    }
    return cnt;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &s[i]);
    }
    ++psum[0][s[0]];

    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < 10; ++j) {
            psum[i][j] = psum[i - 1][j];
        }
        ++psum[i][s[i]];
    }

    int a = 0, b = 0; // closed interval [a, b]
    while(a <= b && b < n) {
        const int length = b - a + 1;
        const int fruit_cnt = get_fruit_count(a, b);

        if(fruit_cnt <= 2) {
            ++b;
            max_length = std::max(max_length, length);
        }
        else {
            ++a;
        }
    }

    printf("%d\n", max_length);
}
