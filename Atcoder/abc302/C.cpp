#include <iostream>
#include <string>

int n, m, dist[10][10];
bool visited[10];
int hist[10];
std::string s[10];

bool calc(int cnt) {
    if(cnt == n) {
        for(int i = 1; i < n; ++i) {
            if(dist[hist[i]][hist[i - 1]] > 1)
                return false;
        }
        return true;
    }

    int s = 0;
    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            visited[i] = true;
            hist[cnt] = i;
            s += calc(cnt + 1);
            visited[i] = false;
        }
    }

    return s;
}

int main() {
    std::cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }

    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            int c = 0;
            for(int k = 0; k < m; ++k) {
                if(s[i][k] != s[j][k]) ++c;
            }
            dist[i][j] = dist[j][i] = c;
        }
    }

    if(calc(0)) {
        std::cout << "Yes";
    }
    else {
        std::cout << "No";
    }
}