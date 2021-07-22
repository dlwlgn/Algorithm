//백트래킹이 들어간 DFS
#include <stdio.h>

int N, count;
int min;

void DFS(int N) {
	if (N == 1) {
		if (min > count) min = count;
		return;
	}

	if (count > min) return;

	count++;
	if (N % 3 == 0) {
		DFS(N / 3);
	}
	if (N % 2 == 0) {
		DFS(N / 2);
	}
	DFS(N - 1);
	count--;
}

int main() {
	scanf("%d", &N);

	count = 0, min = 987654321;
	DFS(N);

	printf("%d\n", min);
}
