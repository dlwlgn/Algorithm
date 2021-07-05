#include <stdio.h>

int memorial[11];

int factorial(int n){
    if(memorial[n]!=0) return memorial[n];
    else {
        memorial[n] = n*factorial(n-1);
        return memorial[n];
    }
}

int main(){
    int N, K;
    scanf("%d %d",&N, &K);
    
    memorial[0] = 1;
    memorial[1] = 1;
    
    int result = factorial(N)/(factorial(K)*factorial(N-K));
    printf("%d",result);
}
