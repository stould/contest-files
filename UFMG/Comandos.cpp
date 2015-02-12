#include <bits/stdc++.h>

using namespace std;

int N, M, K;

int main(void) {
	for ( ; scanf("%d%d%d", &N, &M, &K) == 3; ) {
		if (N == 0 && M == 0 && K == 0) {
			break;
		}

		int X = 0;
		int Y = 0;
		int A, B;

		for (int i = 0; i < K; i++) {
			scanf("%d%d", &A, &B);

			if (i == 0) {
				X = A;
				Y = B;
				continue;
			}

			if (A == X - 1) {
				printf("C");
			} else if (A == X + 1) {
				printf("B");
			} else if (B == Y - 1) {
				printf("E");
			} else if (B == Y + 1) {
				printf("D");
			}
     
			X = A;
			Y = B;
		}
		printf("\n");
	}
	return 0;
}
