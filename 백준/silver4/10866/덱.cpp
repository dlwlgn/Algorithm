#include <iostream>
#include <string>
#define MAX 10001

using namespace std;

int deque[MAX];
int N, rear = 0, front = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string command;
		int number;
		cin >> command;
		if (command == "push_front") {
			cin >> number;
			deque[front] = number;
			front = (--front + MAX) % MAX;
		}
		else if (command == "push_back") {
			cin >> number;
			deque[(++rear) % MAX] = number;
			rear = rear % MAX;
		}
		else if (command == "pop_front") {
			if (front == rear) cout << "-1\n";
			else {
				cout << deque[(front + 1) % MAX] << "\n";
				front = (++front) % MAX;
			}
		}
		else if (command == "pop_back") {
			if (front == rear) cout << "-1\n";
			else {
				cout << deque[rear] << "\n";
				rear = ((--rear) + MAX) % MAX;
			}
		}
		else if (command == "size") {
			cout << (rear - front + MAX) % MAX << "\n";
		}
		else if (command == "empty") {
			if (front == rear) cout << "1\n";
			else cout << "0\n";
		}
		else if (command == "front") {
			if (front == rear) cout << "-1\n";
			else cout << deque[(front + 1) % MAX] << "\n";
		}
		else if (command == "back") {
			if (front == rear) cout << "-1\n";
			else cout << deque[rear] << "\n";
		}
 	}
}
