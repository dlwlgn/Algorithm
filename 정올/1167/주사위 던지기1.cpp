#include <stdio.h>

int N, M;
int path[10];
int used[10];

void print() {
	for (int i = 0; i < N; i++) {
		printf("%d ", path[i]);
	}
	printf("\n");
}

void type1(int lev) { //중복 순열
	if (lev == N) {
		print();
		return;
	}

	
	for (int i = 1; i <= 6; i++) {
		path[lev] = i;
		type1(lev + 1);
	}
}

void type2(int lev) { //순열
	if (lev == N) {
		print();
		return;
	}


	for (int i = 1; i <= 6; i++) {
		if (used[i] == 1) {
			continue;
			
		}
		path[lev] = i;
		used[i] = 1;
		type2(lev + 1);
		used[i] = 0;
	}
}

void type3(int lev, int n) { //중복 조합
	if (lev == N) {
		print();
		return;
	}


	for (int i = n; i <= 6; i++) {
		path[lev] = i;
		type3(lev + 1, i);
	}
}

void type4(int lev, int n) { //조합
	if (lev == N) {
		print();
		return;
	}


	for (int i = n; i <= 6; i++) {
		path[lev] = i;
		type4(lev + 1, i + 1);
	}
}

int main() {
	
	scanf("%d %d", &N, &M);

	if (M == 1) {//중복 순열
		type1(0);
	}
	else if (M == 2) {//순열
		type2(0);
	}
	else if(M == 3) {//중복 조합
		type3(0, 1);
	}
	else {//조합
		type4(0, 1);
	}

}