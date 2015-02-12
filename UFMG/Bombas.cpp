#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

typedef long long Int;

int N, B;
int used[MAXN];
Int EX[MAXN], EY[MAXN], BX[MAXN], BY[MAXN], P[MAXN];

int main(void) {
	for ( ; scanf("%d%d", &N, &B) == 2 && N != 0; ) {
		for (int i = 0; i < N; i++) {
			scanf("%lld%lld", &EX[i], &EY[i]);
			used[i] = -1;
		}
		for (int i = 0; i < B; i++) {
			scanf("%lld%lld%lld", &BX[i], &BY[i], &P[i]);

			for (int j = 0; j < N; j++) {
				if (used[j] == -1) {
					Int dst = (BX[i] - EX[j]) * (BX[i] - EX[j]) + (BY[i] - EY[j]) * (BY[i] - EY[j]);
					if (dst <= P[i] * P[i]) {
						used[j] = i;
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			cout << used[i] << "\n";
		}
	}
	return 0;
}
