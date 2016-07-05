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

const int MAXN = 5000005;
string S;
bool p[MAXN];
vector<string> pal;

bool func(string str) {
	for (int i = 0; i < (int) str.size() / 2; i++) {
		if (str[i] != str[str.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

string to_bin(int x) {
	string ans = "";

	if (x == 0) return "0";

	while (x > 0) {
		ans = char('0' + (x % 2)) + ans;
		x /= 2;
	}

	return ans;
}

int to_int(string str) {
	int ans = 0;
	int pw = 1;
	
	for (int i = (int) str.size() - 1; i >= 0; i--) {
		if (str[i] == '1') {
			ans += pw;
		}
		pw *= 2;
	}
	
	return ans;
}

int main(void) {
	for (int i = 2; i < MAXN; i++) {
		if (!p[i]) {
			string bin = to_bin(i);
			
			if (func(bin)) {
				pal.push_back(bin);
			}

			for (Int j = i * (Int) i; j < MAXN; j += i) {
				p[j] = true;
			}
		}			
	}

	while (cin >> S) {
		int l = 0, h = (int) pal.size() - 1, m;
		int best = -1;

		while (l <= h) {
			m = (l + h) / 2;

			if (to_int(pal[m]) > to_int(S)) {
				best = m;
				h = m - 1;
			} else {
				l = m + 1;
			}
		}

		cout << pal[best] << "\n";
	}
	return 0;
}
