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

int K;
string A, B;

int main(void) {
	for ( ; cin >> K; ) {
		cin >> A >> B;
		int N = (int) A.size();
		Int ans = 1;
		bool ok = true;

		for (int i = 0; i < N; i += K) {
			vector<char> sa, sb;

			int cnt = 0;
			for (int j = i; j < N && cnt < K; j++, cnt++) {
				sa.push_back(A[j]);
				sb.push_back(B[j]);
			}
			sort(sa.begin(), sa.end());
			sort(sb.begin(), sb.end());
			if (sa == sb) {
				for (char c = 'a'; c <= 'z'; c++) {
					int s = count(sa.begin(), sa.end(), c);
					if (s > 0) {
						ans *= s;
					}
				}
			} else {
				ok = false;
			}
		}
		if (!ok) {
			ans = 0;
		}
		printf("%lld\n", ans);
	}
    return 0;
}
