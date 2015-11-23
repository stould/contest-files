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

const int MAXN = 100005;

int N, T;
Int P[110];
bool seen[MAXN];

void gen() {
	srand(time(NULL));

	for (int x = 0; x < 10; x++) {
		int n = 1 + rand() % 7;
		int t = 1 + rand() % 100000;
		
		cout << n << " " << t << "\n";
		for (int i = 0; i < n; i++) {
			cout << 1 + rand() % 50 << " ";
		}
		cout << "\n";
	}
	cout << "0 0\n";
}

int main(void) {
	//gen(); return 0;
	while (cin >> N >> T) {
		if (N == 0 && T == 0) {
			break;
		}

		memset(seen, false, sizeof(seen));

		Int L = 1LL;
		bool ok = true;
		
		for (int i = 0; i < N; i++) {
			cin >> P[i];
			L = lcm(L, P[i]);

			if (T % P[i] != 0) {
				ok = false;
			}
		}
				
		int ans = -1;

		if (ok && L <= T) {		
			for (int i = 2; i <= T; i++) {
				if (!seen[i] && lcm(L, (Int) i) == T) {
					ans = i;
					break;
				}
			}
		}
		if (ans == -1) {
			cout << "impossivel\n";
		} else {
			cout << ans << "\n";
		}
	}
	return 0;
}
