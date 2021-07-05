#include <stdio.h>

int stack[50];
int top = -1;

int main(){
    int T;
    scanf("%d\n",&T);
    for(int i=0; i<T; i++){
        char temp;
        top = -1;
        while(1){
            scanf("%c", &temp);
            if(temp == '\n') break;
            else if(temp == '('){
                stack[++top] = 1;
            }
            else if(temp == ')'){
                if(top == -1){
                    while(temp != '\n') scanf("%c",&temp);
                    top++;
                    break;
                }
                else{
                    top--;
                }
            }
        }
        if(top == -1) printf("YES\n");
        else printf("NO\n");
    }
}
