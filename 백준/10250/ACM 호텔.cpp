#include <cstdio>
int main(){
    int T, H, W, N, RN;
    scanf("%d\n",&T);
    for(int i=0; i<T; i++){
        scanf("%d %d %d",&H,&W,&N);
        if( (N/H)==(double)N/(double)H) RN = H*100 + (N/H);
        else RN = (N%H)*100 + (N/H) + 1;
        printf("%d\n",RN);
    }
}
