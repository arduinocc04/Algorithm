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
        std::cout << " ";

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

    int dir_cnt;
    std::cin >> dir_cnt;

    std::string string_buf;
    std::vector<std::string> buffer;
    for(int i = 0; i < dir_cnt; ++i) {
        std::cin >> string_buf;

        std::vector<int> inverse_slash_idxes;
        for(int j = 0; j < string_buf.size(); ++j)
            if(string_buf[j] == '\\')
                inverse_slash_idxes.push_back(j);
        const int depth = inverse_slash_idxes.size() + 1;

        buffer.clear();
        buffer.resize(depth);

        if(depth == 1) {
            buffer[0] = string_buf;
        }
        else {
            buffer[0] = string_buf.substr(0, inverse_slash_idxes[0]);
        }

        for(int j = 1; j < depth - 1; ++j) {
            buffer[j] = string_buf.substr(inverse_slash_idxes[j - 1] + 1, inverse_slash_idxes[j] - inverse_slash_idxes[j - 1] - 1);
        }

        if(depth != 1)
            buffer[depth - 1] = string_buf.substr(inverse_slash_idxes[inverse_slash_idxes.size() - 1] + 1);

        trie.append(buffer);
    }

    trie.print();

    return 0;
}