#include <stdio.h>
#include <vector>

using namespace std;

int N, M, B;
int floor_list[257];

int main() {
	scanf("%d %d %d", &N, &M, &B);

	vector<vector<int>> arr;

	int temp, min_floor = 987654321, max_floor = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &temp);
			floor_list[temp]++;
			if (min_floor > temp) min_floor = temp;
			if (max_floor < temp) max_floor = temp;
		}
	}

	vector<int> v_temp(2);
	for (int i = 0; i < 257; i++) {
		if (floor_list[i] != 0) {
			v_temp[0] = i; //층의 높이
			v_temp[1] = floor_list[i]; //층의 개수
			arr.push_back(v_temp);
		}
	}

	int length = arr.size();

	int sol = 987654321, sol_floor;
	for (int i = min_floor; i <= max_floor; i++) {
		long long total = 0;
		int inven = B;
		for (int j = 0; j < length; j++) {
			if (i > arr[j][0]) { //맞춰야 할 높이가 더 높은 경우(블럭 놔야 함)
				total += (i - arr[j][0])*(arr[j][1]) * 1;
				inven -= (i - arr[j][0])*(arr[j][1]);
			}
			else if (i < arr[j][0]) { //맞춰야 할 높이가 더 낮은 경우(블럭 치워야 함)
				total += (arr[j][0] - i)*(arr[j][1]) * 2;
				inven += (arr[j][0] - i)*(arr[j][1]);
			}
		}
		if (inven < 0) continue;
		else {
			if (sol >= total) { //뒤쪽에 있는 i가 더 높은 층이므로 = 포함
				sol = total;
				sol_floor = i;
			}
		}
	}
	printf("%d %d", sol, sol_floor);

}
