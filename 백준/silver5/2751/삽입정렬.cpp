#include <stdio.h>

int N, arr[1000001];

void insert() {
	for (int i = 0; i < N; i++) {
		int cur = arr[i];
		for (int j = i - 1; j >= 0; j--) {
			if (cur > arr[j]) {
				arr[j + 1] = cur;
				break;
			}
			else {
				arr[j + 1] = arr[j];
				if (j == 0) arr[j] = cur;
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	insert();

	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}
}
