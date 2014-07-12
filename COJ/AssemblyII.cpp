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

const int MAXN = 60005;
const int INF = INT_MAX / 3;

int N;
int P[MAXN], Q[MAXN], stk[MAXN], in[MAXN];

int funcA(void) {
    int i, top = 0;
	int ans = 0;

    stk[0] = INT_MIN;

    for (i = 0; i < N; ++i) {
        if (Q[i] > stk[top]) {
            stk[++top] = Q[i];
        } else {
            int low = 0, high = top;
            while (low <= high) {
                int mid = (low + high) >> 1;
                if (Q[i] < stk[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            stk[low] = Q[i];
        }
		chmax(ans, top);
        in[i] = top;
    }
	return top;
}

int funcB(void) {
    int i, top = 0;
	int ans = 0;

    stk[0] = INT_MIN;

    for (i = 0; i < N; ++i) {
        if (P[i] > stk[top]) {
            stk[++top] = P[i];
        } else {
            int low = 0, high = top;
            while (low <= high) {
                int mid = (low + high) >> 1;
                if (P[i] < stk[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            stk[low] = P[i];
        }
		chmax(ans, top);
        in[i] = top;
    }
	return top;
}


int main(void) {
	for ( ; scanf("%d", &N) == 1; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
			Q[i] = P[i];
		}
		reverse(Q, Q + N);
		int a = funcA(), b = funcB();

		if (a == b) {
			puts("Caution. I will not intervene.");
		} else {
			puts("Don't worry. I must intervene.");
		}
	}
    return 0;
}
