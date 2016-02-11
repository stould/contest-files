#include <iostream>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 32005;

int N;
pair<int, int> P[15001];
int tree[MAXN];
int cnt[15001];

void add(int x, int add) {
	for (int i = x; i < MAXN; i += (i & -i)) {
		tree[i] += add;
	}
}

int sum(int x) {
	int ans = 0;
	
	for (int i = x; i > 0; i -= (i & -i)) {
		ans += tree[i];
	}
	
	return ans;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i].first >> P[i].second;

		P[i].first += 1;
		P[i].second += 1;

		cnt[sum(P[i].first)] += 1;

		add(P[i].first, 1);
	}
	
	for (int i = 0; i < N; i++) {
		cout << cnt[i] << endl;
	}
	
	return 0;
}
