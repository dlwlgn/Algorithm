#include <stdio.h>

int N, arr[1000001];

bool checkSorted(int a, int b) {
	int i = a;
	while (i <= b - 1) {
		if (arr[i] > arr[i + 1]) return false;
		i++;
	}
	return true;
}

bool checkReverseSorted(int a, int b) {
	int i = a;
	while (i <= b - 1) {
		if (arr[i] < arr[i + 1]) return false;
		i++;
	}
	return true;
}

void swap(int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void Reverse(int a, int b) {
	while (a < b) {
		swap(a, b);
		a++;
		b--;
	}
}

void quick(int start, int end) {
	if (checkSorted(start, end)) return;
	if (checkReverseSorted(start, end)) {
		Reverse(start, end);
	}
	if (start >= end) return;
	int pivot = start;
	int pi = start + 1;
	int pj = end;

	while (pi <= pj) {
		while (arr[pi] <= arr[pivot]) {
			if (pi > pj) break;
			pi++;
		}
		while (arr[pj] >= arr[pivot]) {
			if (pi > pj) break;
			pj--;
		}
		if (pi <= pj) swap(pi, pj);
	}
	
	swap(pivot, pj);
	quick(start, pj - 1);
	quick(pj + 1, end);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	quick(0, N - 1);

	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}
}
