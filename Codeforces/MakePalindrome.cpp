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

string S;
int N;
int cnt[30];

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> S;

	N = (int) S.size();

	for (int i = 0; i < N; i++) {
		cnt[S[i] - 'a'] += 1;
	}

	bool isOdd = N % 2 == 1;
	int cnt_odd = 0;
	
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2 == 1) {
			cnt_odd += 1;
		}
	}

	if (isOdd) cnt_odd -= 1;
	
	for (int x = 0; x < cnt_odd / 2; x++) {
		int fl = -1, fr = -1;
		
		for (int i = 0; i < 26; i++) {
			if (cnt[i] % 2 == 1) {
				fl = i;
				break;
			}
		}
		for (int i = 25; i >= 0; i--) {
			if (cnt[i] % 2 == 1) {
				fr = i;
				break;
			}
		}

		if (fl == fr || fl == -1) {
			break;
		}
		cnt[fl] += 1;
		cnt[fr] -= 1;
	}

	
	int l = 0, r = N - 1;
	
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2 == 1) {
			S[N / 2] = 'a' + i;
			break;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > 0 && cnt[i] % 2 == 0) {
			for (int j = 0; j < cnt[i] / 2; j++) {
				S[l++] = 'a' + i;
				S[r--] = 'a' + i;
			}
		}
	}
	
	cout << S << "\n";
	
	return 0;
}
