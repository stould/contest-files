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

const int MAXN = 300005;

int N, M;
string S;

int main(void) {
	cin >> N >> M >> S;

	S = 'a' + S + 'z';

	N += 2;

	set<int> val_beg;
	set<int> val_end;
	
	set<int>::iterator il, ir;
	
	int ans = 0;

	for (int i = 0; i < N - 1; i++) {
		if (S[i] == S[i + 1] && S[i] == '.') {
			ans += 1;
		}
	}

	for (int i = 0; i < M; i++) {
		int pos;
		char value;
		
		cin >> pos >> value;

		if (S[pos] != '.' && value == '.') {
			if (S[pos - 1] == '.') {
				ans += 1;
			}
			if (S[pos + 1] == '.') {
				ans += 1;
			}
		}
		if (S[pos] == '.' && value != '.') {
			if (S[pos - 1] == '.') {
				ans -= 1;
			}
			if (S[pos + 1] == '.') {
				ans -= 1;
			}
		}

		S[pos] = value;
		cout << ans << "\n";
	}
	return 0;
}
