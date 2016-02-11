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

const int MAXN = 100010;
const int INF = INT_MAX / 5;
const int MAX_V = 1000006;

int N;
pair<int, int> P[MAXN];
int W[MAXN];
int vis[MAXN];
int tree[MAX_V];

int minimal(int pos) {
	int ans = INF;

	while (pos > 0) {
		chmin(ans, tree[pos]);
		pos -= pos & -pos;
	}
	
	return ans;
}

void update(int pos, int val) {
	while (pos < MAX_V) {
		chmin(tree[pos], val);
		pos += pos & -pos;
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i].first >> P[i].second;
	}

	for (int i = 0; i < N; i++) {
		cin >> W[i];
	}

	map<int, vector<int> > check;
	vector<int> ans(N, -1);
	bool valid = true;
	
	sort(P, P + N);
	
	for (int i = 0; i < N; i++) {
		check[P[i].second - P[i].first].push_back(i);
	}	   

	memset(vis, -1, sizeof(vis));

	for (int i = 0; valid && i < N; i++) {
		bool matched = false;
		
		for (int j = 0; j < (int) check[W[i]].size(); j++) {
			int u = check[W[i]][j];
			
			if (vis[u] == -1) {
				ans[i] = u;
				vis[u] = i;
				matched = true;
				break;
			} 
		}
		if (!matched) {
			valid = false;
		}
	}	
	
	for (int i = 0; i < MAX_V; i++) {
		tree[i] = INF;
	}

	for (int i = N - 1; i >= 0; i--) {
		int mn = minimal(P[ans[i]].first + 1);

		if (mn <= P[ans[i]].second + 1) {
			valid = false;
		}

		update(P[ans[i]].first + 1, P[ans[i]].second + 1);
	}
	
	if (!valid) {
		cout << "NO\n";
	}  else {	
		cout << "YES\n";	

		for (int i = 0; i < N; i++) {
			cout << P[ans[i]].first << " " << P[ans[i]].second << "\n";
		}
	}
	return 0;
}
