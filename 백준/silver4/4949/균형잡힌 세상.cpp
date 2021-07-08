#include <string>
#include <iostream>

using namespace std;

int stack[102];
int top = -1;

int main() {
	ios::sync_with_stdio(false);

	string str;
	while (1) {
		getline(cin, str);
		if (str == ".") break;
		int idx = 0, flag = 0;
		while (1) {
			if (str[idx] == '.') break;
			else if (str[idx] == '(') {
				stack[++top] = 1;
			}
			else if (str[idx] == '[') {
				stack[++top] = 2;
			}
			else if (str[idx] == ')') {
				if (stack[top] == 1) {
					top--;
				}
				else {
					flag = 1;
					break;
				}
			}
			else if (str[idx] == ']') {
				if (stack[top] == 2) {
					top--;
				}
				else {
					flag = 1;
					break;
				}
			}
			idx++;
		}
		if (flag) {
			cout << "no\n";
		}
		else {
			if (top == -1) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
		}
		top = -1;
	}
}
