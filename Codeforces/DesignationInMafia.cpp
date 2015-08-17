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

int N;
string S;
Int P[30][30];

Int getCost(char a, char b) {
	Int ans = 100101010101001010LL;
	int ia = a - 'a';
	int ib = b - 'a';

	if (ia == ib) return 0;

	chmin(ans, P[ia][ib]);
	chmin(ans, P[ib][ia]);

	for (int i = 0; i < 26; i++) {
		chmin(ans, P[ia][i] + P[ib][i]);
	}
	
	return ans;
}

int main(void) {
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			cin >> P[i][j];
		}
	}

	for (int k = 0; k < 26; k++) {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				chmin(P[i][j], P[i][k] + P[k][j]);
			}			
		}
	}

	cin >> S;
	N = (int) S.size();
	
	Int ans = 0;

	for (int i = 0; i < N / 2; i++) {
		ans += getCost(S[i], S[N - i - 1]);
	}
	
	cout << ans << endl;
	
	return 0;
}
