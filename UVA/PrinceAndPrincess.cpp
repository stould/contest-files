#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 250 * 250 + 2;

int T;
int N, P, Q;
int A[MAXN], B[MAXN], posA[MAXN], posB[MAXN];
int stk[MAXN], in[MAXN];

int lis(int len) {
    int i, top = 0;
	int ans = 0;

    stk[0] = INT_MIN;

	
    for (int i = 0; i < len; ++i) {
        if (posB[i] > stk[top]) {
            stk[++top] = posB[i];
        } else {
            int low = 0, high = top;
            while (low <= high) {
                int mid = (low + high) >> 1;
                if (posB[i] > stk[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            stk[low] = posB[i];
        }
        in[i] = top;
		chmax(ans, in[i]);
    }
	return top;
}

int main(void) {
	scanf("%d", &T);
	
	for (int t = 1; t <= T; t++) {
		scanf("%d%d%d", &N, &P, &Q);

		P += 1;
		Q += 1;

		for (int i = 0; i <= N * N; i++) {
			A[i] = B[i] = posA[i] = posB[i] = in[i] = stk[i] = 0;
		}

		for (int i = 1; i <= P; i++) {
			scanf("%d", &A[i]);
			posA[A[i]] = i;
		}

		int len = 0;
		for (int i = 1; i <= Q; i++) {
			scanf("%d", &B[i]);
			if (posA[B[i]]) {
				posB[len] = posA[B[i]];
				len++;
			}
		}

		printf("Case %d: %d\n", t, lis(len));
	}
    return 0;
}
