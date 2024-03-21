#include <iostream>
#include <utility>
#include <algorithm>

int n, p[3'010];
using Dot = std::pair<int, int>;
std::pair<Dot, Dot> coords[3'010];

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    const int val = (x1 - x2)*(y3 - y2) - (x3 - x2)*(y1 - y2);
    if(val < 0)
        return 1;
    else if(val == 0)
        return 0;
    return -1;
}

bool intersect(int i, int j) {
    Dot p1 = coords[i].first, p2 = coords[i].second;
    Dot q1 = coords[j].first, q2 = coords[j].second;

    const int val1 = ccw(p1.first, p1.second, p2.first, p2.second, q1.first, q1.second)*ccw(p1.first, p1.second, p2.first, p2.second, q2.first, q2.second);
    const int val2 = ccw(q1.first, q1.second, q2.first, q2.second, p1.first, p1.second)*ccw(q1.first, q1.second, q2.first, q2.second, p2.first, p2.second);

    if(val1 == 0 && val2 == 0) {
        if(p2 < p1) {
            std::pair<int, int> tmp = p2;
            p2 = p1;
            p1 = tmp;
        }
        if(q2 < q1) {
            std::pair<int, int> tmp = q2;
            q2 = q1;
            q1 = tmp;
        }
        return !(p2 < q1 || q2 < p1);
    }
    return val1 <= 0 && val2 <= 0;
}

int find(int n) {
    if(p[n] < 0)
        return n;
    else
        return p[n] = find(p[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);

    if(n1 == n2)
        return;

    p[n1] += p[n2];
    p[n2] = n1;
}

int main() {
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        coords[i] = {{x1, y1}, {x2, y2}};
    }

    for(int i = 0; i < n; ++i)
        p[i] = -1;

    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(intersect(i, j))
                merge(i, j);
        }
    }

    for(int i = 0; i < n; ++i)
        find(i);

    int cnt = 0, max_cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(p[i] < 0) {
            ++cnt;
            max_cnt = std::min(max_cnt, p[i]);
        }
    }

    std::cout << cnt << std::endl;
    std::cout << -max_cnt;
    return 0;
}
