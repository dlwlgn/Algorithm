#include <stdio.h>

int num2(int number){
    int count = 0;
    while(1){
        if(number%2 == 0){
            number /= 2;
            count++;
        }
        else{
            return count;
        }
    }
}

int num5(int number){
    int count = 0;
    while(1){
        if(number%5 == 0){
            number /= 5;
            count++;
        }
        else{
            return count;
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);
    
    int count2 = 0, count5 = 0;
    for(int i=1; i<=N; i++){
        count2 += num2(i);
        count5 += num5(i);
    }
    printf("%d",count5);
}