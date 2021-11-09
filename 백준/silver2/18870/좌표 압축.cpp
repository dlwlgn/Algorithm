#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void init() {

}

int main() {
	init();

	int N;

	scanf("%d", &N);

	vector<int> arr1(N);
	vector<int> arr2(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr1[i]);
		arr2[i] = arr1[i];
	}

	sort(arr2.begin(), arr2.end());
	
	map<int, int> m;

	int prev = 1000000001, cur;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cur = arr2[i];

		if (prev != cur) { //맨 처음 숫자거나 숫자의 변화
			m[cur] = cnt;
			
			cnt++;
		}
		
		prev = cur;
	}
	
	for (int i = 0; i < N; i++) {
		printf("%d ", m[arr1[i]]);
	}

	return 0;
}