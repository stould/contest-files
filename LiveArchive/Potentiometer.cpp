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

const int MAXN = 200010;

int N;
Int P[MAXN], tree[MAXN];
string S;

Int sum(int pos) {
	Int ans = 0;

	for ( ; pos > 0; pos -= (pos & -pos)) {
		ans += tree[pos];
	}
	
	return ans;
}

void setVal(int pos, int val) {
	int curr = sum(pos) - sum(pos - 1);

	for ( ; pos <= N; pos += (pos & -pos)) {
		tree[pos] += val - curr;
	}
}


int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int test = 1;
	bool check = false;
	
	for ( ; cin >> N && N != 0; ) {
		if (check) cout << endl;
		check = true;
		
		for (int i = 1; i <= N; i++) {
			cin >> P[i];
			setVal(i, P[i]);
		}

		cout << "Case " << test++ << ":" << endl;

		while (cin >> S) {
			if (S == "END") break;
			
			if (S == "S") {
				int X, R;
				cin >> X >> R;

				setVal(X, R);
			} else {
				int X, Y;				
				cin >> X >> Y;

				int ans = sum(Y) - sum(X - 1);

				cout << ans << endl;
			}
		}		
	}

	return 0;
}
