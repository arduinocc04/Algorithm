#include <cstdio>
#include <stack>
#include <string>
#include <queue>
char string[1000010], explosive[40];
std::stack<char> st;
std::stack<char> tmp;
int main() {
    scanf("%s", string);
    scanf("%s", explosive);
    std::string str = string;
    std::string exp = explosive;
    int explen = exp.length();
    for(int i = 0; i < str.length(); i++) {
        st.push(str[i]);
        if(st.size() >= explen) {
            bool flag = true;
            for(int j = 0; j < explen; j++) {
                if(st.top() != exp[explen - j - 1]) {
                    flag = false;
                    break;
                }
                tmp.push(st.top());
                st.pop();
            }
            if(!flag) {
                while(tmp.size()) {
                    st.push(tmp.top());
                    tmp.pop();
                }
            }
        }
    }
    std::stack<char> ans;
    for(int i = 0; i < st.size(); i++) {
        ans.push(st.top());
        st.pop();
    }
    for(int i = 0; i < ans.size(); i++) {
        printf("%c", ans.top());
        ans.pop();
    }
}