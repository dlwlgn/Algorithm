#include <stdio.h>

struct member{
    int age;
    char name[101];
};

int N;
member arr[100001], temp_arr[100001];

void merge(int start, int end) {
	int point1 = start, point2 = (start + end) / 2 + 1;
	int count = start;
	
	while (count <= end) {
		if (point1 <= (start + end) / 2 && point2 <= end) {
			if (arr[point1].age <= arr[point2].age) {
				temp_arr[count] = arr[point1];
				point1++;
			}
			else {
				temp_arr[count] = arr[point2];
				point2++;
			}
		}
		else if (point1 > (start + end) / 2) {
			temp_arr[count] = arr[point2];
			point2++;
		}
		else if (point2 > end) {
			temp_arr[count] = arr[point1];
			point1++;
		}
		count++;
	}

	for (int i = start; i <= end; i++) {
		arr[i] = temp_arr[i];
	}
}

void mergeSort(int start, int end) {
	if (start == end) return;
	
	mergeSort(start, (start + end) / 2);
	mergeSort((start + end) / 2 + 1, end);

	merge(start, end);
}

int main() {
	scanf("%d", &N);
    char temp;
	for (int i = 0; i < N; i++) {
        int pnt = 0;
        scanf("%d ", &arr[i].age);
        while(1){
            scanf("%c",&temp);
            if(temp == '\n') break;
            arr[i].name[pnt++] = temp;
        }
        arr[i].name[pnt] = '\0';
	}

	mergeSort(0, N - 1);

	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i].age);
        int pnt = 0;
        while(1){
            printf("%c",arr[i].name[pnt++]);
            if(arr[i].name[pnt]=='\0') break;
        }
        printf("\n");
	}
}
