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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 200005;

int N, M;
int A[MAXN], B[MAXN];

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	sort(A, A + N);

	for (int i = 0; i < M; i++) {
		int l = 0, h = N - 1, m;
		int best = 0;
		
		while (l <= h) {
			m = (l + h) / 2;

			if (A[m] <= B[i]) {
				chmax(best, m + 1);
				l = m + 1;
			} else {
				h = m - 1;
			}
		}

		cout << best << " ";
	}
	cout << "\n";
	return 0;
}
