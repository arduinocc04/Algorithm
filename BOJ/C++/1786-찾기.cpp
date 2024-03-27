#include <iostream>
#include <string>
#include <vector>

std::string s, p;

std::vector<int> ans;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::getline(std::cin, s);
    std::getline(std::cin, p);

    std::vector<int> failure(p.size());
    failure[0] = -1;
    int consec_cnt = 0;
    for(int i = 1; i < p.size(); ++i) {
        if(p[consec_cnt] == p[i]) {
            failure[i] = consec_cnt++;
        }
        else {
            consec_cnt = 0;
            failure[i] = -1;
        }
    }

    std::vector<int> idx(p.size() + 1);
    for(int j = 0; j <= p.size(); ++j) {
        int t = j;
        if(t > 0) --t;
        while(t > 0 && failure[t] == -1) --t;
        idx[j] = t;
    }

    int i = 0, j = 0;
    while(i + j < s.size()) {
        if(s[i + j] != p[j] || j == p.size()) {
            if(j == p.size()) {
                ans.push_back(i + 1);
            }
            j = idx[j];
            i += j - failure[j];
            j = failure[j] + 1;
        }
        else
            ++j;
    }
    if(j == p.size())
        ans.push_back(i + 1);

    std::cout << ans.size() << "\n";
    for(int a: ans) {
        std::cout << a << "\n";
    }
}
