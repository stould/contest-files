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

int N, K;
pair<int, int> P[110];

int main(void) {
	cin >> N >> K;

	vector<pair<int, int> > ans;
	int op = 0;

	for (int i = 0; i < N; i++) {
		cin >> P[i].first;
		P[i].second = i + 1;
	}

	for (int i = 0; i < K; i++) {
		sort(P, P + N);

		if (abs(P[0].first - P[N - 1].first) <= 1) {
			break;
		}

		op += 1;
		ans.push_back(make_pair(P[N - 1].second, P[0].second));

		P[N - 1].first -= 1;
		P[0].first += 1;
	}

	sort(P, P + N);

	cout << P[N - 1].first - P[0].first << " " << op << "\n";

	for (int i = 0; i < op; i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}

    return 0;	
}
