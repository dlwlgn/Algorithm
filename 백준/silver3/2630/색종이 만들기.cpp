#include <stdio.h>

int N, w_cnt = 0, b_cnt = 0;
int p_map[128][128];

void check_map(int i, int j, int size) {
	int col = p_map[i][j];
	int flag = 1;
	for (int r = i; r < i + size; r++) {
		for (int c = j; c < j + size; c++) {
			if (col != p_map[r][c]) {
				flag = 0;
				break;
			}
		}
		if (!flag) break;
	}

	if (flag) {
		if (col == 1) b_cnt++;
		else w_cnt++;
	}
	else {
		check_map(i + size / 2, j + size / 2, size / 2);
		check_map(i + size / 2, j, size / 2);
		check_map(i, j + size / 2, size / 2);
		check_map(i, j, size / 2);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &p_map[i][j]);
		}
	}

	check_map(0, 0, N);

	printf("%d\n%d", w_cnt, b_cnt);
}