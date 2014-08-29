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

const Int INF = 1000101010010000LL;

int N, K;
string S;
int cnt[26];

int main(void) {
	cin >> N >> K >> S;

	for (int i = 0; i < N; i++) {
		cnt[S[i] - 'A'] += 1;
	}

	sort(cnt, cnt + 26);

	int used = 0;
	Int ans = 0LL;

	for (int i = 0; i < 26; i++) {
		if (used + cnt[25 - i] <= K) {
			used += cnt[25 - i];
			ans += cnt[25 - i] * (Int) cnt[25 - i];
		} else {
			ans += (K - used) * (Int) (K - used);
			break;
		}
	}

	cout << ans << endl;

    return 0;
}
