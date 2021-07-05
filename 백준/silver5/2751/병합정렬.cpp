#include <stdio.h>

int N, arr[1000001], temp_arr[1000001];

void merge(int start, int end) {
	int point1 = start, point2 = (start + end) / 2 + 1;
	int count = start;
	
	while (count <= end) {
		if (point1 <= (start + end) / 2 && point2 <= end) {
			if (arr[point1] <= arr[point2]) {
				temp_arr[count] = arr[point1];
				point1++;
			}
			else {
				temp_arr[count] = arr[point2];
				point2++;
			}
		}
		else if (point1 > (start + end) / 2) {
			temp_arr[count] = arr[point2];
			point2++;
		}
		else if (point2 > end) {
			temp_arr[count] = arr[point1];
			point1++;
		}
		count++;
	}

	for (int i = start; i <= end; i++) {
		arr[i] = temp_arr[i];
	}
}

void mergeSort(int start, int end) {
	if (start == end) return;
	
	mergeSort(start, (start + end) / 2);
	mergeSort((start + end) / 2 + 1, end);

	merge(start, end);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	mergeSort(0, N - 1);

	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}
}
