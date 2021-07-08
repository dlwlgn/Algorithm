#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool cmp(vector<int> a, vector<int> b) {
	if (a[1] == b[1]) {
		return a[0] < b[0];
	}
	else {
		return a[1] < b[1];
	}
}

int main() {
	scanf("%d", &N);
	vector<vector<int>> indexs(N, vector<int>(2));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &indexs[i][j]);
		}
	}
	sort(indexs.begin(), indexs.end(), cmp);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", indexs[i][j]);
		}
		printf("\n");
	}
}
