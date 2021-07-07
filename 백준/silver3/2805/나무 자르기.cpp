#include <iostream>
#include <vector>

using namespace std;

long long N, M;
vector<int> trees;

int binarysearch(int a, int b) {
	int c = (a + b) / 2;

	long long total = 0;
	for (int i = 0; i < N; i++) {
		if(trees[i] > c) total += (trees[i] - c);
	}
	if (total > M) return 2;
	else if (total == M) return 1;
	else return 0;
}

int main() {
	cin >> N >> M;
	trees.resize(N);

	int max = 0;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
		if (max < trees[i]) max = trees[i];
	}
	int start = 0, end = max, sol;
	
	while (1) {
		if (start >= end) {
			sol = end - 1;
			break;
		}
		
		int mid = (start + end) / 2;
		int check = binarysearch(start, end);

		//안되는 애들 중에서 제일 작은 애를 찾자
		if (check == 2) start = mid + 1;
		else if (check == 1) {
			sol = mid;
			break;
		}
		else end = mid;
	}
	printf("%d", sol);
}
