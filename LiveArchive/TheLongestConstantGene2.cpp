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

const int MAXL  = 15;
const int MAXN  = 7000005;
const uInt BASE = 33;


int T, L;
int N[MAXL];
string S[MAXL];
uInt P[MAXN];
uInt H[MAXL][MAXN];

uInt getHash(int id, int l, int r) {
	uInt ans = H[id][r];

	if (l != 0) {
		ans -= H[id][l - 1];
	}

	ans *= P[MAXN - 1 - r];
	

	
	return ans;
}

int main(void) {
	cin >> T;

	P[0] = 1;

	for (int i = 1; i < MAXN; i++) {
		P[i] = P[i - 1] * BASE;
	}


	for (int t = 0; t < T; t++) {	
		int smallestLen = INT_MAX;
		
		cin >> L;		
		
		for (int i = 0; i < L; i++) {
			cin >> S[i];

			N[i] = (int) S[i].size();

			smallestLen = min(smallestLen, N[i]);

			for (int j = 0; j < N[i]; j++) {
				H[i][j] = (S[i][j] - 'A') * P[j];
				
				if (j > 0) {
					H[i][j] += H[i][j - 1];
				}
			}
		}
	
	
		int l = 0, h = smallestLen, m;
		int best = 0;

		while (l <= h) {
			m = (l + h) / 2;
		
			unordered_map<uInt, int> seen;
			bool ok = false;

			for (int i = 0; i < L; i++) {
				unordered_map<uInt, bool> local_seen;
				
				for (int j = m; j < N[i]; j++) {
					uInt curr_hash = getHash(i, j - m, j);

					if (!local_seen[curr_hash]) {
						seen[curr_hash] += 1;

						if (seen[curr_hash] == L) {
							ok = true;
						}
					}
				
					local_seen[curr_hash] = true;
				}
			}

			if (ok) {
				l = m + 1;
				best = m + 1;
			} else {
				h = m - 1;
			}
		}
		
		cout << best << "\n";
	}
	return 0;
}
