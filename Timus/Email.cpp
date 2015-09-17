#include <iostream>
#include <climits>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 2002;
const Int MOD = 1000000007LL;
const int INF = INT_MAX / 4;

string A, B;
int N, M;
pair<int, Int> dp[MAXN][MAXN];

//len, ways
pair<int, Int> func(int i, int j) {
	if (i >= N or j >= M) {
		return make_pair(max(N - i, M - j), 1LL);
	} else {
		pair<int, Int>& ans = dp[i][j];

		if (ans.first == -1) {
			ans.first = INF;
			ans.second = 0;

			if (A[i] == B[j]) {
				pair<int, Int> next = func(i + 1, j + 1);
				next.first += 1;

				if (ans.first > next.first) {
					ans = next;
				}
			} else {
				pair<int, Int> ia = func(i + 1, j);
				ia.first += 1;
				
				if (ans.first > ia.first) {
					ans = ia;
				} else if (ans.first == ia.first) {
					ans.second += ia.second;
				}
				
				pair<int, Int> ib = func(i, j + 1);
				ib.first += 1;
				
				if (ans.first > ib.first) {
					ans = ib;
				} else if (ans.first == ib.first) {
					ans.second += ib.second;
				}
			}
		}

		ans.second = ((ans.second % MOD) + MOD) % MOD;
		
		return ans;
	}
}

int main(void) {
	cin >> A >> B;

	N = (int) A.size();	
	M = (int) B.size();


	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			dp[i][j].first = -1;
		}
	}
	
	cout << func(0, 0).second << endl;
	
	return 0;
}
