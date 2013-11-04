#include <bits/stdc++.h>
using namespace std;

typedef long long int Int;

const int inf = 0x3f3f3f3f;
const Int hugeinf = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-9;

const int MAXN = 100005;

int N, M;

int K[MAXN];
int A[MAXN];

int main(void) {
	int i, j;

	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		memset(A, 0, sizeof(A));

        int x;
        
		for (i = 0; i < N; i++) {
			scanf("%d", &M);	

            memset(K, 0, sizeof(K));		

			for (j = 0; j < M; j++) {
				scanf("%d", &x);

				K[x] += 1;
			}

            for (j = 1; j <= 1000; j++) {
                K[j] += K[j - 1];
            }

			for (j = 0; j <= 1000; j++) {
		        A[j] += abs(K[j] - (M - K[j]));
			}
		}

		int ans = 10001010;

		for (i = 1; i <= 1000; i++) {
			ans = min(ans, A[i]);
		}

		printf("%d\n", ans);
	}
	return 0;
}

