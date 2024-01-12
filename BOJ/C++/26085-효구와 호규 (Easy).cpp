#include <cstdio>

int n, m;
bool board[1'010][1'010];
int cnt[3];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
			cnt[board[i][j]]++;
		}
	}
	if(cnt[0] % 2 || cnt[1] % 2) {
		printf("-1\n");
		return 0;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m - 1; j++) {
			if(!(board[i][j]^board[i][j+1])) {
				printf("1\n");
				return 0;
			}
		}
	}

	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < m; j++) {
			if(!(board[i][j]^board[i + 1][j])) {
				printf("1\n");
				return 0;
			}
		}
	}

	printf("-1\n");
}
