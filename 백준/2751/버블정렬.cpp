#include <stdio.h>

int N, arr[1000001];

void bubble() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	bubble();

	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}
}
