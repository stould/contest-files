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

const int MAXN = 500005;

int N;
pair<int, int> P[MAXN];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	return a.first < b.first;	
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i].first >> P[i].second;
	}

	sort(P, P + N, cmp);
	
	int ans = 0;

	for (int i = 0; i < N; i++) {
		ans += 1;

		int j = i;

		while (j < N && P[j].first <= P[i].second) {
			j += 1;
		}

		i = j - 1;
	}
	
	cout << ans << "\n";
	
	return 0;
}
