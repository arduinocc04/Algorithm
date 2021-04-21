#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

int n, m;
std::set<std::string> a;
std::string tmp;
std::vector<std::string> ans;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> n >> m;
    for(int i = 0; i < n; i++) {
        std::cin >> tmp;
        a.insert(std::string(tmp));
    }
    for(int i = 0; i < m; i++) {
        std::cin >> tmp;
        if(a.count(std::string(tmp))) {
            ans.push_back(std::string(tmp));
        }
    }
    std::sort(ans.begin(), ans.end());
    std::cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << "\n";
    }
}