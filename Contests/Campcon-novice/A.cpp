#include <cstdio>

void rotateLeft(char** mat) {
    int a, b, c;
    a = mat[0][0];
    b = mat[0][1];
    c = mat[1][0];

    mat[0][1] = mat[1][1];
    mat[0][0] = b;
    mat[1][0] = a;
    mat[1][1] = c;
}

char T[3][3] = {{'.', 'O'}, {'P', '.'}}, F[3][3] = {{'I', '.'}, {'.', 'P'}}, Lz[3][3] = {{'O', '.'}, {'.', 'P'}};

char *(tt)[3] = T, (*ff)[3] = F, (*lz)[3] = Lz;
char direction, map[3][3];

int n;

bool same(char a[2][2], char b[2][2]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            if(a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

int main() {
    scanf("%c", &direction);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            scanf(" %c", &map[i][j]);
        }
    }
    switch (direction) {
        case 'S':
            n = 0;
            break;
        case 'E':
            n = 1;
            break;
        case 'N':
            n = 2;
            break;
        case 'W':
            n = 3;
            break;
        default:
            break;
    }

    for(int i = 0; i < n; i++) {
        rotateLeft(tt);
        rotateLeft(ff);
        rotateLeft(lz);
    }

}