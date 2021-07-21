#include <stdio.h>

struct dist
{
	int number;
	int distan;
};

int N, M;
dist Queue[100000];
int front = -1, rear = -1;
bool relation[101][101];
int min_length[101][101];

int main() {
	scanf("%d %d", &N, &M);

	int temp1, temp2;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &temp1, &temp2);
		relation[temp1][temp2] = true;
		relation[temp2][temp1] = true;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) min_length[i][j] = 0;
			else min_length[i][j] = 987654321;
		}
	}


	for (int j = 1; j <= N; j++) {
		front = -1, rear = -1;
		Queue[++rear] = { j,1 };

		while (1) {

			for (int i = 1; i <= N; i++) {
				if (relation[Queue[front + 1].number][i] == true || relation[i][Queue[front + 1].number] == true) {
					if (min_length[j][i] >= Queue[front + 1].distan) {
						min_length[j][i] = Queue[front + 1].distan;
						min_length[i][j] = Queue[front + 1].distan;
						Queue[++rear] = { i,Queue[front + 1].distan + 1 };
					}
				}
			}
			front++;

			if (front == rear) break;

		}


	}

	int min_total = 987654321;
	int min_idx;

	for (int i = 1; i <= N; i++) {
		double temp_total = 0;
		for (int j = 1; j <= N; j++) {
			temp_total += min_length[i][j];
		}
		if (min_total > temp_total) {
			min_total = temp_total;
			min_idx = i;
		}

	}

	printf("%d\n", min_idx);
}
