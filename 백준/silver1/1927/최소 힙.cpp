#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX_N 100001

using namespace std;

struct heap {
	int arr[MAX_N];
	int size;
};
//완전이진트리는 다음과 같은 특성을 가진다.
//1부터 인덱스를 시작할 경우
//부모의 인덱스는 자신의 인덱스/2
//왼쪽 자식의 인덱스는 자신의 인덱스*2
//오른쪽 자식의 인덱스는 자신의 인덱스*2+1


heap minheap;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapInsert(int number) {
	int here = ++minheap.size;
	while (number < minheap.arr[here/2] && here != 1) {
		minheap.arr[here] = minheap.arr[here/2];
		here /= 2;
	}
	minheap.arr[here] = number;
}

int heapDelete() {
	if (minheap.size == 0) {
		return 0;
	}
	
	int number = minheap.arr[1];
	minheap.arr[1] = minheap.arr[minheap.size--];

	int here = 1, child;
	while (1) {
		child = here * 2;
		if (minheap.size >= child + 1 && minheap.arr[child] > minheap.arr[child + 1]) {
			//오른쪽 자식이 있고 오른쪽 자식이 왼쪽 자식보다 더 작으면
			child++;//오른쪽 자식 선택
		}
		
		if (child > minheap.size || minheap.arr[here] < minheap.arr[child]) {
			//자식이 존재하지 않거나 자식보다 부모가 더 작으면
			break;//탈출
		}

		swap(&minheap.arr[here], &minheap.arr[child]);
		here = child;
	}

	return number;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	minheap.size = 0;

	int N;

	cin >> N;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp == 0) {
			int sol = heapDelete();
			cout << sol << "\n";
		}
		else {
			heapInsert(temp);
		}
	}
}


