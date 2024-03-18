#include <iostream>
#include <stack>

#define MAX_SEQ_LEN 1'000'010

int len_seq, seq[MAX_SEQ_LEN], cnt[MAX_SEQ_LEN], NGF[MAX_SEQ_LEN];

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> len_seq;
    for(int i = 0; i < len_seq; ++i) {
        std::cin >> seq[i];
        ++cnt[seq[i]];
    }

    std::stack<int> st;
    st.push(0);

    for(int i = 1; i < len_seq; ++i) {
        while(st.size() && cnt[seq[i]] > cnt[seq[st.top()]]) {
            NGF[st.top()] = seq[i];
            st.pop();
        }
        st.push(i);
    }

    const int stack_size = st.size();
    for(int i = 0; i < stack_size; ++i) {
        const int idx = st.top();
        NGF[idx] = -1;
        st.pop();
    }

    for(int i = 0; i < len_seq; ++i)
        std::cout << NGF[i] << " ";
}
