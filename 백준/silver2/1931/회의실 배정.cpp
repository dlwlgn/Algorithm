#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
	if (a[1] < b[1]) {
		return true;
	}
	else if (a[1] == b[1]) {
		if (a[0] < b[0]) {
			return true;
		}
		else if (a[0] == b[0]) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	int N;
	scanf("%d", &N);

	vector<vector<int>> arr(N, vector<int>(2));
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	sort(arr.begin(), arr.end(), cmp);
	
	int count = 0, start = 0, end = 0;
	for (int i = 0; i < N; i++) {
		if (end <= arr[i][0]) {
			count++;
			start = arr[i][0];
			end = arr[i][1];
		}
	}
	printf("%d", count);
}