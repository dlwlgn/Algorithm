#include <stdio.h>


int N, total, max = 0;
int arr[300];
int memoization[300][4];

void DFS(int stack, int step) {
	if (stack == 3) return;
	if (step == N - 1) {
		if (max < total) max = total;
		return;
	}
	else if (step > N - 1) {
		return;
	}

	if (memoization[step][stack] > total) return;
	else memoization[step][stack] = total;

	total += arr[step + 1];
	DFS(stack + 1, step + 1);
	total -= arr[step + 1];
	
	total += arr[step + 2];
	DFS(1, step + 2);
	total -= arr[step + 2];
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	total = arr[0];
	DFS(1, 0);
	total = arr[1];
	DFS(1, 1);

	printf("%d", max);
}