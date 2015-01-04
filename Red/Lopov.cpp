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

const int MAXN = 300005;

int N, K, C;
pair<int, int> P[MAXN];

bool cmpPair(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main(void) {
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		cin >> P[i].first >> P[i].second;
	}

	multiset<int> q;

	for (int i = 0; i < K; i++) {
		cin >> C;
		q.insert(C);
	}
	
	sort(P, P + N, cmpPair);
	
	Int sum = 0LL;
	
	for (int i = 0; i < N; i++) {
		if (q.empty()) break;
		
		if (q.lower_bound(P[i].first) != q.end()) {
			sum += P[i].second;
			q.erase(q.lower_bound(P[i].first));
		}
	}
	
	cout << sum << "\n";
	
    return 0;
}
