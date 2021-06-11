#include <stdio.h>


int Uclid(int a, int b) {
	int temp = a % b;
	if (temp == 0) {
		return b;
	}
	return Uclid(b, temp);
}

int main() {
	int A, B;
	scanf("%d %d", &A, &B);
	if (B > A) {
		int temp = A;
		A = B;
		B = temp;
	}

	int sol1 = Uclid(A, B);
	int sol2 = B * (A / sol1);

	printf("%d\n", sol1);
	printf("%d\n", sol2);
}
