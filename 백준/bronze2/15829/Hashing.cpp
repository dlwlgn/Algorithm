#include <stdio.h>

int mod = 1234567891;

long long pow(int a, int b) {
	long long result = 1;
	for (int i = 0; i < b; i++) {
		result *= a;
        result %= mod;
	}
	return result;
}

int main(){
    int L;
    scanf("%d ", &L);
    
    char temp;
    long long total = 0;
    for(int i=0; i<L; i++){
        scanf("%c",&temp);
        total += (pow(31, i)*(temp - 'a' + 1)) % mod;
        
        if(total > 1234567891) total = total % mod;
    }
    printf("%lld", total);
}
