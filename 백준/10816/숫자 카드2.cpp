#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> card;
int N, M;

int lower_bound(int n) {
	int first = 0, last = N - 1;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;
		if (card[mid] < n) {
			first = mid + 1;
		}
		else {
			last = mid - 1;
		}
	}
	return first;
}

int upper_bound(int n) {
	int first = 0, last = N - 1;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;
		if (card[mid] <= n) {
			first = mid + 1;
		}
		else {
			last = mid - 1;
		}
	}
	return last + 1;
}

int main() {
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		card.push_back(temp);
	}

	sort(card.begin(), card.end());

	scanf("%d\n", &M);
	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);
		int ub = upper_bound(temp);
		int lb = lower_bound(temp);
		printf("%d ", ub - lb);
	}

}
