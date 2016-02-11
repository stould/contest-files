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
string S;

Int fat(int x) {
	Int ans = 1LL;

	for (int i = 2; i <= x; i++) {
		ans *= (Int) i;		
	}
	
	return ans;
}

int main(void) {
	cin >> N;
	
	for (int t = 1; t <= N; t++) {
		cin >> S;
		
		vector<int> seen(26, 0);
		
		for (int i = 0; i < (int) S.size(); i++) {
			seen[S[i] - 'A'] += 1;
		}

		Int ans = fat(S.size());
		
		for (int i = 0; i < 26; i++) {
			if (seen[i] >= 2) {
				ans /= fat(seen[i]);
			}
		}

		cout << "Data set " << t << ": " << ans << "\n";
	}
	return 0;
}
