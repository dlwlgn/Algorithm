//백트래킹이 들어간 BFS
#include <stdio.h>

struct queue {
	int N;
	int count;
};

int N;
int min;
queue Q[10000000];
int rear = -1, front = -1;

void BFS() {
	
	while (1) {
		if (front == rear) break;
		
		int temp_N = Q[front + 1].N;
		int temp_count = Q[front + 1].count;



		if (min < temp_count) {
			front++;
			continue;
		}

		if (temp_N == 1) {
			if (min > temp_count) min = temp_count;
			front++;
			continue;
		}

		if (temp_N % 3 == 0) Q[++rear] = { temp_N / 3,temp_count + 1 };
		if (temp_N % 2 == 0) Q[++rear] = { temp_N / 2,temp_count + 1 };
		Q[++rear] = { temp_N - 1,temp_count + 1 };

		front++;
	}

}

int main() {
	scanf("%d", &N);

	min = 987654321;
	Q[++rear] = { N, 0 };

	BFS();

	printf("%d\n", min);
}
