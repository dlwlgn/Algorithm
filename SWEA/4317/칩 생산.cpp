#include <iostream>

int box[11][26];
int H, W, total = 0, max = 0;
using namespace std;

void DFS(int r, int c) {
	
	if (r >= H - 1) {
		if (max < total) max = total;
		return;
	}


	for (int i = r; i < H - 1; i++) {
		bool check = false;
		for (int j = 0; j < W - 1; j++) {
			if (i == r && !check) {
				j = c;
				check = true;
			}
			if (box[i][j] == 0 && box[i + 1][j] == 0 && box[i][j + 1] == 0 && box[i + 1][j + 1] == 0) {
				total += 1;
				box[i][j] = 1;
				box[i + 1][j] = 1;
				box[i][j + 1] = 1;
				box[i + 1][j + 1] = 1;
				if (j == W - 2 || j == W - 3) {
					DFS(i + 1, 0);
				}
				else {
					DFS(i, j + 2);
				}
				box[i][j] = 0;
				box[i + 1][j] = 0;
				box[i][j + 1] = 0;
				box[i + 1][j + 1] = 0;
				total -= 1;
			}
		}
	}
	if (max < total) max = total;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> box[i][j];
			}
		}

		max = 0, total = 0;
		DFS(0,0);

		cout << '#' << tc << ' ' << max << '\n';
	}
}
