#include <stdio.h>

int N, arr[1000001];

void selection() {
	for (int i = 0; i < N - 1; i++) {
		int min = 1000001, min_arr;
		for (int j = i; j < N; j++) {
			if (min > arr[j]) {
				min = arr[j];
				min_arr = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min_arr];
		arr[min_arr] = temp;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	selection();

	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}
}
