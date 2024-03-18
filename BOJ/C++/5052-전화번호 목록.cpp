#include <iostream>
#include <string>

#define MAX_PHONE_NUM_LENGTH 15
#define NODE_SIZE 11
#define MAX_TRIE_DEPTH 11

struct Node {
    Node * next[NODE_SIZE] = {nullptr, };
    bool is_end = false;
};

class Trie {
public:
    Trie() {
        head = new Node;
    }
    ~Trie();
    void append_phone_num(std::string_view phone_num);
    bool is_consistent(std::string_view phone_num);
private:
    Node * head = nullptr;
};

void dfs_delete_impl(Node * now) {
    if(now == nullptr)
        return;

    for(int i = 0; i < NODE_SIZE; ++i) {
        if(now->next[i] != nullptr) {
            dfs_delete_impl(now->next[i]);
        }
    }
    delete now;
}

Trie::~Trie() {
    dfs_delete_impl(head);
}

void Trie::append_phone_num(std::string_view phone_num) {
    Node * now = head;
    for(int i = 0; i < phone_num.size(); ++i) {
        const int digit = phone_num[i] - '0';

        if(now->next[digit] == nullptr)
            now->next[digit] = new Node;

        now = now->next[digit];
    }
    now->is_end = true;
}

bool Trie::is_consistent(std::string_view phone_num) {
    Node * now = head;
    for(int i = 0; i < phone_num.size(); ++i) {
        const int digit = phone_num[i] - '0';

        if(now->next[digit] == nullptr)
            return true;

        if(now->next[digit]->is_end)
            return false;

        now = now->next[digit];
    }

    if(now == nullptr)
        return true;
    else
        return false;
}

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);


    int testcase_cnt;
    std::cin >> testcase_cnt;

    bool possible;
    int phone_num_cnt;
    while(testcase_cnt--) {
        std::cin >> phone_num_cnt;

        Trie trie{};
        possible = true;
        std::string phone_num;
        for(int i = 0; i < phone_num_cnt; ++i) {
            std::cin >> phone_num;

            if(trie.is_consistent(phone_num))
                trie.append_phone_num(phone_num);
            else {
                possible = false;
            }
        }

        if(possible)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    return 0;
}