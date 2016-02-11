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

const int MAXN = 300005;

int N;
int P[MAXN];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	vector<pair<int, int> > ans;

	bool valid = false;

	for (int i = 0; i < N; i++) {
		int j = i;
		bool ok = false;

		map<int, int> mem;
		
		while (j < N) {
			mem[P[j]] += 1;
			
			if (mem[P[j]] > 1) {
				valid = true;
				ok = true;
				break;
			}

			j += 1;
		}
		
		if (ok) {
			ans.push_back(make_pair(i + 1, j));		
		} else {
			if (!ans.empty()) {
				ans.back().second = j;
			}
		}
		
		i = j;
	}
	
	if (!valid) {
		cout << "-1" << endl;
	} else {
		cout << ans.size() << endl;

		for (int i = 0; i < (int) ans.size(); i++) {
			if (i + 1 < (int) ans.size()) {
				ans[i].second = ans[i + 1].first - 1;
			} else {
				ans[i].second = N;
			}
			
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	}
	return 0;
}
