import os
default = """#include <cstdio>

int T, n;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
    }
    return 0;
}
"""
dir_ = os.path.join(os.getcwd(), input('input round name! >>>'))
if not os.path.isdir(dir_):
    os.mkdir(dir_)
for i in 'ABCDEF':
    with open(os.path.join(dir_,i + '.cpp'), 'w', encoding='utf8') as f:
        f.write(default)
