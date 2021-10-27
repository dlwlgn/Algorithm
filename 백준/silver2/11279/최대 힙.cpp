#include <stdio.h>

int maxHeap[100001];
int heapLen = 0;

void maxHeapInsert(int num) {

	maxHeap[++heapLen] = num;

	int pnt = heapLen;
	int parent;

	while (1) {
		parent = pnt / 2;

		//루트에 도달하거나, 부모가 자신보다 크면 멈춘다.
		if (pnt == 1 || maxHeap[parent] >= maxHeap[pnt]) {
			break;
		}
		//루트가 아니고, 자신이 부모보다 크면 swap 연산을 한다.
		else {
			int temp = maxHeap[pnt];
			maxHeap[pnt] = maxHeap[parent];
			maxHeap[parent] = temp;
		}

		pnt = parent;
	}

}

int maxHeapDelete() {
	int maxVal;
	if (heapLen == 0) {
		return 0;
	}
	
	maxVal = maxHeap[1];
	maxHeap[1] = maxHeap[heapLen--];

	int pnt = 1;
	int child; 
	while (1) {
		child = pnt * 2;

		//둘 중 큰 자식을 대표로 삼음(자식 2개를 가지고 있는지도 체크)
		if (maxHeap[child] < maxHeap[child + 1] && child < heapLen) child++;
		//자식이 하나도 없으면 멈춰야 함
		else if (child > heapLen) break;

		//두 자식이 모두 자신보다 작거나 같을때 멈춰야 함. 
		if (maxHeap[child] <= maxHeap[pnt]) {
			break;
		}
		//더 큰 자식과 교체를 실행한다.
		else {
			int temp = maxHeap[pnt];
			maxHeap[pnt] = maxHeap[child];
			maxHeap[child] = temp;
		}

		pnt = child;
	}


	return maxVal;
}

int main() {
	int N;

	scanf("%d", &N);

	int temp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);

		if (temp == 0) {
			int num = maxHeapDelete();
			printf("%d\n", num);
		}
		else {
			maxHeapInsert(temp);
		}

	}
	


	return 0;
}