#include <stdio.h>

int N, M, cnt;
int adjacent_node[1001][1001];
bool visited_node[1001];

void init() {
	cnt = 0;
	for (int i = 0; i < 1001; i++) {
		visited_node[i] = false;
		for (int j = 0; j < 1001; j++) {
			adjacent_node[i][j] = 0;
		}
	}
}

void DFS(int node) {
	if (visited_node[node]) return;

	visited_node[node] = true;

	for (int i = 1; i <= adjacent_node[node][0]; i++) {
		DFS(adjacent_node[node][i]);
	}
}

int main() {
	init();
	scanf("%d %d", &N, &M);

	int u, v;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);

		adjacent_node[u][0]++;
		adjacent_node[u][adjacent_node[u][0]] = v;
		adjacent_node[v][0]++;
		adjacent_node[v][adjacent_node[v][0]] = u;

	}

	for (int i = 1; i <= N; i++) {
		if (visited_node[i]) continue;
		DFS(i);
		cnt++;
	}

	printf("%d\n", cnt);
}