#include <stdio.h>

int N, S, E, b;

int main(void) {
	scanf("%d", &N);
	
	int i;

	S = 0;

	for (i = 0; i < N; i++) {
		scanf("%d", &b);
		S += b;
	}
	
	scanf("%d", &E);

	if (S == E) {
		puts("Acertou");
	} else {
		puts("Errou");
	}
	return 0;
}
