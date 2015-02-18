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

const int MAXN = 100005;

int N, L, X, Y;
Int P[MAXN];

int main(void) {
	cin >> N >> L >> X >> Y;

	map<Int, int> rank;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	int found = 0;
	vector<int> ans;
	
	for (int i = 0; i < N; i++) {
		if (P[i] >= X) {
			if (!binary_search(P, P + N, P[i] - X)) {			
				rank[P[i] - X] |= (1 << 0);
			} else {
				found |= (1 << 0);
			}
		} 
		if (P[i] + X <= L) {
			if (!binary_search(P, P + N, P[i] + X)) {
				rank[P[i] + X] |= (1 << 0);
			} else {
				found |= (1 << 0);
			}
		}
		if (P[i] >= Y) {
			if (!binary_search(P, P + N, P[i] - Y)) {
				rank[P[i] - Y] |= (1 << 1);
			} else {
				found |= (1 << 1);
			}
		}
		if (P[i] + Y <= L) {
			if (!binary_search(P, P + N, P[i] + Y)) {
				rank[P[i] + Y] |= (1 << 1);
			} else {
				found |= (1 << 1);
			}
		}
	}
	
	if (found != 3) {	
		for (map<Int, int>::iterator it = rank.begin(); it != rank.end(); it++) {
			if (it->second == 3) {
				ans.clear();
				ans.push_back(it->first);
				break;
			} else {
				bool got = false;
				
				for (int i = 0; i < 2; i++) {
					if ((it->second & (1 << i)) && !(found & (1 << i))) {
						got = true;
					}
				}
				if (got) {
					found ^= it->second;
					ans.push_back(it->first);					
				}
			}
		}
	}

	cout << ans.size() << "\n";

	for (int i = 0; i < ans.size(); i++) {
		if (i) cout << " ";
		cout << ans[i];
		if (i == ans.size() - 1) {
			cout << "\n";
		}
	}	
	
    return 0;
}
