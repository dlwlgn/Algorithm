#include <stdio.h>
#include <cmath>

int map_set[64][64];
int N;

void check_map(int N, int i, int j) {
	int flag = 0;
	int num = map_set[i][j];
	for (int i_idx = i; i_idx < i+N; i_idx++) {
		for (int j_idx = j; j_idx < j+N; j_idx++) {
			if (map_set[i_idx][j_idx] != num) {
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}
	if (flag) {
		printf("(");
		check_map(N/2, i, j);
		check_map(N/2, i, j + N / 2);
		check_map(N/2, i + N / 2, j);
		check_map(N/2, i + N / 2, j + N / 2);
		printf(")");
	}
	else {
		printf("%d", num);
	}
}

int main() {
	scanf("%d", &N);
	char temp_char;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c ", &temp_char);
			map_set[i][j] = temp_char - '0';
		}
	}

	check_map(N, 0, 0);

}