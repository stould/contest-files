#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long Int;

const int MAXN = 10003;
int N;

Int dp[MAXN][MAXN];
Int V[MAXN];

int main(void) {
    for ( ; scanf("%d", &N) == 1; ) {
		for (int i = 0; i < N; i++) {
            scanf("%lld", &V[i]);			
        }
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - i; j++) {
				if (i == 0) {
					dp[j][j] = V[j];
				} else if (i == 1) {
					dp[j][j + i] = max(V[j], V[j + 1]);
				} else {
					dp[j][j + i] = max(V[j] + min(dp[j + 2][j + i], dp[j + 1][j + i - 1]), V[j + i] + min(dp[j][j + i - 2], dp[j + 1][j + i - 1]));
				}
			}
		}
		printf("%lld\n", dp[0][N-1]);
    }
    return 0;
}
