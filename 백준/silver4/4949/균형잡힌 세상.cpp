#include <stdio.h>

int Q[1000002];
int front = -1, rear = -1;

int main(){
    int N;
    scanf("%d", &N);
    rear = N-1;
    for(int i=1; i<=N; i++){
        Q[i-1] = i;
    }
    if(N==1){
        printf("%d", Q[front+1]);
    }
    else{
        while(1){
            front++;
            if((rear-front)==1) break;
            Q[++rear] = Q[++front];
        }
        printf("%d",Q[front+1]);
    }
    
    
}
