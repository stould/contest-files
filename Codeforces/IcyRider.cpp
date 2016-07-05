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

const int INF = INT_MAX / 2;
int N, M;
vector<int> gr[100005];
map<int, vector<int> > mp;

int main(void) {
	cin >> N >> M;

	vector<int> ans(N, INF);
	
	for (int i = 0; i < M; i++) {
		int cnt, val, nx;
		cin >> cnt >> val;

		for (int j = 0; j < cnt; j++) {
			cin >> nx;
			nx -= 1;
			
			mp[val].push_back(nx);
			gr[nx].push_back(nx);
			
			ans[nx] = min(ans[nx], val);
		}
	}
	return 0;
}
