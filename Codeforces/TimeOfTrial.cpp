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
typedef unsigned uint;

const int MAXN = 100005;

int N;
pair<int, int> P[MAXN];

int main(void) {
	cin >> N;

	int t = 0;
	
	for (int i = 0; i < N; i++) {		
		cin >> P[i].first;
	}
	for (int i = 0; i < N; i++) {		
		cin >> P[i].second;
	}

	sort(P, P + N);
	bool ok = false;
	
	for (int i = 0; i < N; i++) {
		t += P[i].second;
		if (P[i].first <= t) {
			ok = true;
			break;
		}
	}

	if (ok) {
		cout << "Redemption\n";
	} else {
		cout << "Dire victory\n";
	}
	
	return 0;
}
