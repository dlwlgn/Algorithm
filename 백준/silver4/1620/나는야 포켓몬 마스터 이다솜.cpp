#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	vector<string> book(N + 1); //번호가 키 포켓몬 이름이 값
	vector<pair<string, int>> reversebook(N + 1); //포켓몬 이름이 키, 번호가 값
	string temp;

	for (int i = 1; i <= N; i++) {
		cin >> temp;
		book[i] = temp;

		reversebook[i] = { temp, i };
	}

	sort(reversebook.begin(), reversebook.end());

	for (int i = 0; i < M; i++) {
		cin >> temp;
		if ('0' <= temp[0] && temp[0] <= '9') {
			int total = 0, len = temp.length();
			for (int j = 0; j < len; j++) {
				total = total * 10 + (temp[j] - '0');
			}
			cout << book[total] << "\n";
		}
		else {
			int low = 1, high = N;
			while (low <= high) {
				int mid = (low + high) / 2;
				if (reversebook[mid].first > temp) {
					high = mid - 1;
				}
				else if (reversebook[mid].first < temp) {
					low = mid + 1;
				}
				else {
					cout << reversebook[mid].second << "\n";
					break;
				}

			}
		}
	}
}


