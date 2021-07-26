#include <iostream>
#include <string>

using namespace std;

int main() {
	int total = 0, plus = 0, minus = 0;
	int phase = 0; //0(시작), 1(양수), 2(음수)

	string str;

	cin >> str;

	int len = str.length();

	for (int i = 0; i < len; i++) {
		char temp = str[i];

		if (temp == '+') {
			if (phase == 1) {
				total += plus;
				plus = 0;
			}
			else if (phase == 2) {
				total -= minus;
				minus = 0;
			}
		}
		else if (temp == '-') {
			if (phase == 0) {
				phase = 2;
			}
			else if (phase == 1) {
				total += plus;
				plus = 0;
				phase = 2;
			}
			else if (phase == 2) {
				total -= minus;
				minus = 0;
			}
		}
		else if ('0' <= temp && temp <= '9') {
			if (phase == 0) {
				plus = (temp - '0');
				phase = 1;
			}
			else if (phase == 1) {
				plus = plus * 10 + (temp - '0');
			}
			else if (phase == 2) {
				minus = minus * 10 + (temp - '0');
			}
		}

		if (i == len - 1) {
			if (phase == 1) {
				total += plus;
				plus = 0;
			}
			else if (phase == 2) {
				total -= minus;
				minus = 0;
			}
			break;
		}
	}

	cout << total;
}
