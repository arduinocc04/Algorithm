#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Node {
    std::vector<Node *> next;
    std::string data;
    bool is_end = false;
};

class Trie {
public:
    Trie() {
        head = new Node;
    }
    ~Trie();
    void append(const std::vector<std::string> & cave_data);
    void print();
private:
    Node * head = nullptr;
};

void dfs_delete_impl(Node * now) {
    for(int i = 0; i < now->next.size(); ++i) {
        dfs_delete_impl(now->next[i]);
    }
    delete now;
}

Trie::~Trie() {
    dfs_delete_impl(head);
}

void Trie::append(const std::vector<std::string> & cave_data) {
    Node * now = head;
    for(int i = 0; i < cave_data.size(); ++i) {
        bool node_exists = false;
        int node_idx = 0;
        for(; node_idx < now->next.size() && now->next[node_idx]->data <= cave_data[i]; ++node_idx) {
            if(now->next[node_idx]->data == cave_data[i]) {
                node_exists = true;
                break;
            }
        }

        if(node_exists) {
            now = now->next[node_idx];
            continue;
        }

        Node * to_insert = new Node;
        to_insert->data = cave_data[i];
        now->next.insert(now->next.begin() + node_idx, to_insert);

        now = now->next[node_idx];
    }
}

bool compare(const Node * const a, const Node * const b) {
    return a->data < b->data;
}

void print_dfs_impl(Node * const now, int depth) {
    for(int i = 0; i < depth; ++i)
        std::cout << "--";

    std::cout << now->data << "\n";
    std::sort(now->next.begin(), now->next.end(), compare);

    for(int i = 0; i < now->next.size(); ++i) {
        print_dfs_impl(now->next[i], depth + 1);
    }
}

void Trie::print() {
    std::sort(head->next.begin(), head->next.end(), compare);
    for(int i = 0; i < head->next.size(); ++i) {
        print_dfs_impl(head->next[i], 0);
    }
}

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    Trie trie{};

    int info_cnt;
    std::cin >> info_cnt;

    int depth;
    std::vector<std::string> buffer;
    for(int i = 0; i < info_cnt; ++i) {
        std::cin >> depth;
        buffer.clear();
        buffer.resize(depth);

        for(int j = 0; j < depth; ++j)
            std::cin >> buffer[j];

        trie.append(buffer);
    }

    trie.print();

    return 0;
}