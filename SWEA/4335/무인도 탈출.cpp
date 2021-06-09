#include <stdio.h>


int box_arr[21][3];
int N, max_height;
bool visited_box[21];

void DFS(int width, int depth, int total_height) { 
	
	for (int i = 0; i < N; i++) {
		if (!visited_box[i]) break;
		if (i == N - 1) {
			if (total_height > max_height) {
				max_height = total_height;
				return;
			}
		}
	}
	
	
	for (int i = 0; i < N; i++) {
		if (visited_box[i]) continue;
		for (int j = 0; j < 3; j++) {
			int temp[2] = { box_arr[i][(j + 1) % 3] , box_arr[i][(j + 2) % 3] };
			if (temp[0] > temp[1]) {
				if (width >= temp[0] && depth >= temp[1]) {
					visited_box[i] = true;
					DFS(temp[0], temp[1], total_height + box_arr[i][j]);
					visited_box[i] = false;
					
				}
			}
			else {
				if (width >= temp[1] && depth >= temp[0]) {
					visited_box[i] = true;
					DFS(temp[1], temp[0], total_height + box_arr[i][j]);
					visited_box[i] = false;
				}
			}
			
			if (j == 2) {
				visited_box[i] = true;
				DFS(width, depth, total_height);
				visited_box[i] = false;
			}
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d", &box_arr[i][0], &box_arr[i][1], &box_arr[i][2]);
			visited_box[i] = false;
		}
		max_height = 0;
		DFS(10000, 10000, 0);

		printf("#%d %d\n", tc, max_height);
	}
}
