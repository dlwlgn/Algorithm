#include <stdio.h>

int N, number[10001];

int main() {
	scanf("%d", &N);
    int temp;
    
    int max = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
        number[temp]++;
        if(max < temp) max = temp;
	}

	for (int i = 1; i <= max; i++) {
		for(int j=0; j<number[i]; j++){
            printf("%d\n",i);
        }
	}
}
