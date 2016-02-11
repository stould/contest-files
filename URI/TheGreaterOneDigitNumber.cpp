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

string S, P;

int Ssum(string& arg) {
	int ans = 0;

	for (int i = 0; i < (int) arg.size(); i++) {
		ans += arg[i] - '0';
	}

	return ans;
}

int dsum(int x) {
	int ans = 0;

	if (x != 0) {
		while (x > 0) {
			ans += (x % 10);
			x /= 10;
		}
		
	}
	
	return ans;
}

int main(void) {
	while (cin >> S >> P) {
		if (S == "0" && P == "0") {
			break;
		}
		int ss = Ssum(S);
		int pp = Ssum(P);

		while (1) {
			int ns = dsum(ss);

			if (ss == ns) break;
			ss = ns;
		}
		while (1) {
			int np = dsum(pp);

			if (pp == np) break;
			pp = np;
		}

		if (ss > pp) {
			cout << "1\n";
		} else if (ss < pp) {
			cout << "2\n";
		} else {
			cout << "0\n";
		}
	}
	return 0;
}
