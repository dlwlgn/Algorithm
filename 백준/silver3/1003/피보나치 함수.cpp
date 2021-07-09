#include <stdio.h>

int T;
int memorial[41][2];

int main(){
    scanf("%d",&T);
    memorial[0][0] = 1;
    memorial[0][1] = 0;
    
    memorial[1][0] = 0;
    memorial[1][1] = 1;
    
    for(int i=2; i<=40; i++){
        memorial[i][0] = memorial[i-1][0] + memorial[i-2][0];
        memorial[i][1] = memorial[i-1][1] + memorial[i-2][1];
    }
    int temp;
    for(int tc=1; tc<=T; tc++){
        scanf("%d",&temp);
        printf("%d %d\n", memorial[temp][0], memorial[temp][1]);
    }
}
