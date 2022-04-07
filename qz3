#include <stdio.h>

FILE* hanoi;

int multiplication(int i, int j) {
	if (j < 10) {
		printf("%d*%d=%d ", i, j, i*j);	
		return multiplication(i, j+1);
	}
	else if (i < 9){
		j = 1;
		printf("\n");
		return multiplication(i+1, j);
	} 
}

void hanoi_tower(int n, char A, char B, char C) {	
	if (n>0) {
	    hanoi_tower(n - 1, A, C, B);
	    hanoi = fopen("hanoi.txt", "a+");
	    fprintf(hanoi,"Move disk %d from %c to %c\n", n, A, C);  
	    fclose(hanoi);
	    hanoi_tower(n - 1, B, A, C);
	}
}

void rec_dec(char* s) {
	for(char* t = s; *t; t++) {
		printf("%c,", *s);
		return rec_dec(s+1);
	}
}

int main() {
	char s[] = "1234567890";
	printf("func#1--\n");
	rec_dec(s);
	printf("\n\nfunc#2--\n");
	hanoi_tower(16, 'A', 'B', 'C');
	printf("\nfunc#3--\n");	
	multiplication(1, 1);
	return 0;
}
