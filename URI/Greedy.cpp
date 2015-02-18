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
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 1000006;

int T, N, K, S;
Int arr[MAXN], B[MAXN];
int Q[MAXN];

Int maxSlidingWindow(Int A[], int n, int w, Int B[]) {
	int b = 0, e = 0;
	Int ans = 0LL;
	for (int i = 0; i < w; i++) {
		while (!(b == e) && A[i] >= A[Q[e-1]]) {
			e -= 1;
		}
		Q[e++] = i;
	}
	for (int i = w; i < n; i++) {
		B[i-w] = A[Q[b]];
		ans += B[i-w];
		while (!(e == b) && A[i] >= A[Q[e-1]])
			e--;
		while (!(e == b) && Q[b] <= i-w)
			b += 1;
		Q[e++] = i;
	}
	ans += A[Q[b]];

	return ans;
}

int main(void) {
	scanf("%d", &T);

	for ( ; T--; ) {
		scanf("%d%d%d", &N, &K, &S);
		
		arr[0] = S;
		for (int i = 1; i < N; ++i) {
			arr[i] = (1LL*arr[i-1]*1103515245 + 12345) % (2147483648LL);
		}
		
		Int sum = maxSlidingWindow(arr, N, K, B);
		
		printf("%lld\n", sum);		
	}
    return 0;
}
