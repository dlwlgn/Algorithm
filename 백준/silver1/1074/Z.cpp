#include <stdio.h>
#include <math.h>

int N, r, c;
int r_s, r_e, c_s, c_e;
int start, end;
int quadrant;

int check_quadrant(int r, int c) {
	int r_c = (r_e - r_s + 1) / 2 - 1;
	int c_c = (c_e - c_s + 1) / 2 - 1;

	if (r <= r_c) { //1사분면 또는 4사분면
		if (c <= c_c) { //4사분면
			return 4;
		}
		else { //1사분면
			return 1;
		}
	}
	else { //2사분면 또는 3사분면
		if (c <= c_c) { //3사분면
			return 3;
		}
		else { //2사분면
			return 2;
		}
	}
}

void change_rc(int quadrant) {
	int r_c = (r_e - r_s + 1) / 2 - 1;
	int c_c = (c_e - c_s + 1) / 2 - 1;
	int quarter = (end - start + 1) / 4;
	
	r_e = (r_e + 1) / 2 - 1;
	c_e = (c_e + 1) / 2 - 1;

	if (quadrant == 1) {
		start += quarter;
		end = start + quarter - 1;
		c -= c_c + 1;
	}
	else if (quadrant == 2) {
		start += (quarter * 3);
		r -= r_c + 1;
		c -= c_c + 1;
	}
	else if (quadrant == 3) {
		start += (quarter * 2);
		end = start + quarter - 1;
		r -= r_c + 1;
	}
	else if (quadrant == 4) {
		end = start + quarter - 1;
	}
}

int main() {
	scanf("%d %d %d", &N, &r, &c);

	r_s = 0;
	r_e = pow(2, N) - 1;
	c_s = 0;
	c_e = pow(2, N) - 1;

	start = 0;
	end = pow(2, 2*N) - 1;

	while (N != 0) {
		quadrant = check_quadrant(r, c);
		N--;
		change_rc(quadrant);
		
		printf("quadrant = %d\n", quadrant);
		printf("start = %d end = %d\n", start, end);
		printf("r = %d c = %d\n", r, c);
		printf("N = %d\n", N);
	}
	
	printf("sol = %d\n", start);
}
