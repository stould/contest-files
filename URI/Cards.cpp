#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long Int;

const int MAXN = 10107;
int N;

Int dp[MAXN][MAXN];
int V[MAXN];


int readInt () {
	bool minus = false;
	int result = 0;
	char ch;

	ch = getchar();

	while (1) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') {
	    minus = true;
    } else {
        result = ch-'0';
    }

	while (1) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result * 10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

Int func(int i, int j) {
    if (i + 1 == j) return (Int) max(V[i], V[j]);

    Int& ans = dp[i][j];

    if (ans != -1) return ans;

    return ans = max(V[i] + min(func(i + 2, j), func(i + 1, j - 1)), V[j] + min(func(i, j - 2), func(i + 1, j - 1)));
}

int main(void) {
    int i, j;
    for ( ; scanf("%d", &N) == 1; ) {
        for (i = 0; i < N; i++) {
            V[i] = readInt();
            for (j = i + 1; j < N; j++) {
                dp[i][j] = -1LL;
            }
        }
        printf("%lld\n", func(0, N - 1));
    }
    return 0;
}
