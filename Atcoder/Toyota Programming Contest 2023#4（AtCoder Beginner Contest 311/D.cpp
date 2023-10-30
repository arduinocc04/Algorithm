#include <iostream>
#include <string>

int n, m;
std::string map[210];
bool visited[210][210][4];


void dfs(int nowR, int nowC, int mode) { //mode: 0 ^ 1 > 2 _ 3 < 4: rest
    // std::cout << "HI!" << nowR <<" " <<nowC  << " " << mode << std::endl;
    if(mode != 4) {
        visited[nowR][nowC][mode] = true;
    }
    else {
        for(int i = 0; i < 4; i++) visited[nowR][nowC][i] = true;
    }
    // std::cout << "HI" << nowR <<" " <<nowC  << " " << mode << std::endl;
    switch (mode)
    {
    case 0:
        if(map[nowR - 1][nowC] == '.') {
            dfs(nowR - 1, nowC, mode);
        }
        else {
            dfs(nowR, nowC, 4);
        }
        break;
    case 1:
        if(map[nowR][nowC + 1] == '.') {
            dfs(nowR, nowC + 1, mode);
        }
        else {
            dfs(nowR, nowC, 4);
        }
        break;
    case 2:
        if(map[nowR + 1][nowC] == '.') {
            dfs(nowR + 1, nowC, mode);
        }
        else {
            dfs(nowR, nowC, 4);
        }
        break;
    case 3:
        if(map[nowR][nowC - 1] == '.') {
            dfs(nowR, nowC - 1, mode);
        }
        else {
            dfs(nowR, nowC, 4);
        }
        break;
    case 4:
        if(map[nowR -1][nowC] == '.' && !visited[nowR - 1][nowC][0]) dfs(nowR, nowC, 0);
        if(map[nowR][nowC + 1] == '.' && !visited[nowR][nowC + 1][1]) dfs(nowR, nowC, 1);
        if(map[nowR + 1][nowC] == '.' && !visited[nowR + 1][nowC][2]) dfs(nowR, nowC, 2);
        if(map[nowR][nowC - 1] == '.' && !visited[nowR][nowC - 1][3]) dfs(nowR, nowC, 3);
        break;
    }
}

int main() {
    std::cin >> n >> m;
    for(int i = 0; i < n; i++) {
        std::cin >> map[i];
    }
    int aa = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == '#') {
                for(int k = 0; k < 4; k++) {
                    visited[i][j][k] = true;
                }
                aa++;
            }
        }
    }
    dfs(1, 1, 4);
    int cnt = 0;
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         std::cout << map[i][j];
    //     }
    //     std::cout << std::endl;
    // }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            bool flag = false;
            for(int k = 0; k < 4; k++) {
                if(visited[i][j][k]) {
                    flag = true;
                    break;
                }
            }
            // std::cout <<flag;
            cnt += flag;
        }
        // std::cout<<std::endl;
    }
    std::cout << cnt - aa;
}
