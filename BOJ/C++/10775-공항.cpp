#include <cstdio>

int gate_cnt, plane_cnt, possible_max_empty_gate[100'010];

int find_empty_gate(int max) {
    if(max == possible_max_empty_gate[max]) return max;
    return possible_max_empty_gate[max] = find_empty_gate(possible_max_empty_gate[max]);
}

void update(int gate) {
    possible_max_empty_gate[gate] = gate - 1;
}

int main() {
    scanf("%d", &gate_cnt);
    scanf("%d", &plane_cnt);

    for(int i = 0; i <= gate_cnt; ++i)
        possible_max_empty_gate[i] = i;

    int ans = 0;
    for(int i = 0; i < plane_cnt; ++i) {
        int max_gate;
        scanf("%d", &max_gate);

        const int gate = find_empty_gate(max_gate);
        if(gate == 0) break;

        ++ans;
        update(gate);
    }

    printf("%d\n", ans);
}