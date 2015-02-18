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

const int MAXN = 110;

int N, K;
pair<int, int> P[MAXN];

int main(void) {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> P[i].first;
		P[i].second = i + 1;
	}

	sort(P, P + N);

	int ans = 0;
	vector<int> ans_v;
	
	for (int i = 0; i < N; i++) {
		if (K - P[i].first < 0) break;
		K -= P[i].first;
		ans += 1;
		ans_v.push_back(P[i].second);
	}
	
	cout << ans << endl;

	sort(ans_v.begin(), ans_v.end());
	
	for (int i = 0; i < (int) ans_v.size(); i++) {
		cout << ans_v[i] << " ";
	}
	cout << endl;
	
    return 0;
}
