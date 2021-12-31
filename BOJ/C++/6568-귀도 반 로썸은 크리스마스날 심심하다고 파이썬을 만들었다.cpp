#include <cstdio>

int cmd, param, pc, gasan, mem[40], cnt;
bool flag;
int getCmd(int cmd) {
    return (cmd & (1 << 5)) + (cmd & (1 << 6)) * 2 + (cmd & (1 << 7)) * 4;
}

int getParam(int cmd) {
    int res = 0;
    int tmp = 1;
    for(int i = 0; i < 5; i++) {
        res += (cmd & (1 << i)) * tmp;
        tmp *= 2;
    }
    return res;
}

char* getGasan(int gasan) {
    static char res[9];
    for(int i = 0; i < 8; i++) {
        res[i] = (gasan & (1 << (7-i))) + '0';
    }
    return res;
}

int calc(int str, int len) {
    int res = 0;
    int tmp = 1;
    for(int i = 0; i < len; i++) {
        res += (str & (1 << i))*tmp;
        tmp *= 2;
    }
    return res;
}

int main() {
    cnt = 0;
    flag = false;
    while(scanf("%d", &cmd) != EOF) {
        param = getParam(cmd);
        cmd = getCmd(cmd);
        cnt++;
        if(flag && (cnt <=32)) continue;
        if(cnt > 33) {
            flag = false;
            cnt = 1;
        }
        pc++;
        if(cmd == 0) {
            mem[param] = gasan;
        }
        else if(cmd == 1) {
            gasan = mem[param];
        }
        else if(cmd == 2) {
            if(gasan == 0) {
                pc = param;
            }
        }
        else if(cmd == 4) {
            gasan--;
        }
        else if(cmd == 5) {
            gasan++;
        }
        else if(cmd == 6) {
            pc = param;
        }
        else if(cmd == 7) {
            printf("%s\n", getGasan(gasan));
            flag = true;
        }
        printf("%d\n", cmd);
        gasan = calc(gasan, 8)%256;
        pc = calc(pc, 5)%64;
    }
}