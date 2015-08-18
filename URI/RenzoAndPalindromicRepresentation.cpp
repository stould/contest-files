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

int T, N;

int main(void) {
	cin >> T;

	while (T--) {
		cin >> N;

		vector<int> ans;
		
		for (int base = 2; base <= 16; base++) {
			vector<int> rep;
			int val = N;

			while (val > 0) {
				rep.push_back(val % base);
				val /= base;
			}

			bool ok = true;
			
			for (int i = 0; i < (int) rep.size(); i++) {
				if (rep[i] != rep[rep.size() - i - 1]) {
					ok = false;
				}
			}
			if (ok) {
				ans.push_back(base);
			}
		}		

		if (ans.empty()) {
			cout << "-1\n";
		} else {
			for (int i = 0; i < (int) ans.size(); i++) {
				if (i) cout << " ";
				cout << ans[i];
			}
			cout << "\n";
		}
	}
	return 0;
}
