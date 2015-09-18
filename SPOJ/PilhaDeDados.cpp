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

int N;
vector<vector<int> > D;

int getInv(int x) {
	if (x == 0) {
		return 5;
	} else if (x == 1) {
		return 3;
	} else if (x == 2) {
		return 4;
	} else if (x == 3) {
		return 1;
	} else if (x == 4) {
		return 2;
	} else {
		return 0;
	}
}

int func(int pos, int head, int best) {
	if (pos == N) {
		return best;
	} else {
		int ans = 0;
		
		for (int i = 0; i < 6; i++) {
			if (D[pos][i] == head) {
				int inv = getInv(i);
				int mx = 0;
				
				
				for (int j = 0; j < 6; j++) {
					if (j != i && j != inv) {
						chmax(mx, D[pos][j]);
					}
				}
				ans = max(ans, func(pos + 1, D[pos][inv], best + mx));
				break;
			}			
		}
		return ans;
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		D.push_back(vector<int>(6, 0));

		for (int j = 0; j < 6; j++) {
			cin >> D.back()[j];
		}					
	}

	int ans = 0;

	for (int i = 1; i <= 6; i++) {
		vector<int> s(4, 0);
		ans = max(ans, func(0, i, 0));
	}
	cout << ans << "\n";
	
	return 0;
}
