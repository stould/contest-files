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

const int MAXN = 100005;

int N, M;
int H[MAXN], D[MAXN];
Int LtR[MAXN];
Int RtL[MAXN];

int pr(int x) {
	return (x - 1) < 0 ? N - 1 : x - 1;
}

int nx(int x) {
	return (x + 1) >= N ? 0 : x + 1;
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> D[i];

		LtR[i] = D[i];

		if (i > 0) {
			LtR[i] += D[i - 1];
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		RtL[i] = D[i];

		if (i != N - 1) {
			RtL[i] += D[i + 1];
		}
	}

	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}

	int A, B;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		A--;
		B--;
		
		Int ans = 0LL;
		
		if (A <= B) {
			int l = pr(A);
			int r = nx(B);

			cout << l << " " << r << "\n";
			
			if (l < r) {
				ans = 2 * (H[l] + H[r]) + LtR[l] + RtL[r];
			} else {
				ans = 2 * (H[l] + H[r]) + LtR[r] + RtL[l];
			}
		} else {
			int l = nx(A);
			int r = pr(B);

			ans = 2 * (H[l] + H[r]) + LtR[r] - (l - 1 < 0 ? 0 : LtR[l - 1]);			
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}
