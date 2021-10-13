#include <stdio.h>

int n, total = 0, cnt = 0;

void DFS(){
    if(total == n){
        cnt++;
        return;
    }
    else if(total > n){
        return;
    }
    
    for(int i=1; i<=3; i++){
        total += i;
        DFS();
        total -= i;
    }
}

int main(){
    int T;
    scanf("%d", &T);
    
    for(int tc=1; tc<=T; tc++){
        scanf("%d", &n);
        
        DFS();
        
        printf("%d\n",cnt);
        total = 0;
        cnt = 0;
    }
}