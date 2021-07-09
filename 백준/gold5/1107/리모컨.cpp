#include <stdio.h>
#include <math.h>

int N, M;
int broken[10];

int number_possible(int number) {
	int length = 0;

	while (1) {
		if (broken[number % 10]) return 0;
		number /= 10;
		length++;
		
		if (number == 0) break;
	}
	return length;
}

int main() {
	scanf("%d\n%d", &N, &M);

	int temp;
	for (int i = 0; i < M; i++) {
		scanf("%d", &temp);
		broken[temp] = 1;
	}

	int min = abs(N - 100);

	int N_P = number_possible(N);
	if (N_P > 0) {
		if (min > N_P) min = N_P;
	}

	for (int i = N - 1; i >= 0; i--) {
		int temp_low = number_possible(i);
		if (temp_low) {
			if (min > (temp_low + (N - i))) {
				min = temp_low + (N - i);
				break;
			}
		}
	}
	
	for (int i = N + 1; i <= 1000000; i++) {
		int temp_high = number_possible(i);
		if (temp_high) {
			if (min > (temp_high + (i - N))) {
				min = temp_high + (i - N);
				break;
			}
		}
	}

	
	printf("%d", min);
}
