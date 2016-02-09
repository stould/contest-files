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

const int MAXN = 10005;

int N, Q;
string S[MAXN];
map<string, int> memo;
int id = 1;
map<int, vector<int> > base;

int func(string arg) {
	if (memo[arg] == 0) {  
		memo[arg] = id++;
	}

	return memo[arg];
}


int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> S[i];

		for (int j = 0; j < (int) S[i].size(); j++) {
			for (int k = 1; k + j <= (int) S[i].size(); k++) {
				int v = func(S[i].substr(j, k));
				
				base[v].push_back(i);
			}
		}
	}

	for (int i = 1; i < id; i++) {
		base[i].resize(unique(base[i].begin(), base[i].end()) - base[i].begin());
	}

	cin >> Q;

	while (Q--) {
		int A, B;
		string arg;
		
		cin >> A >> B >> arg;

		int hash = func(arg);
		int r = upper_bound(base[hash].begin(), base[hash].end(), B - 1) - base[hash].begin();
		int l = lower_bound(base[hash].begin(), base[hash].end(), A - 1) - base[hash].begin();

		int ans = r - l;		

		cout << ans << "\n";
	}

	return 0;
}
