#include <stdio.h>

int n;
int memoization[1001];

int tile(int N) {
	if (memoization[N] != -1) {
		return memoization[N];
	}
	else {
		memoization[N] = ((tile(N - 1) % 10007) + (tile(N - 2) % 10007)) % 10007;
		return memoization[N];
	}
}

void init() {
	for (int i = 0; i < 1001; i++) {
		memoization[i] = -1;
	}
	memoization[1] = 1;
	memoization[2] = 2;
}

int main() {
	init();
	scanf("%d", &n);

	int sol = tile(n);

	printf("%d\n", sol);
	return 0;
}