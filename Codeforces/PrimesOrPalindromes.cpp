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

const int MAXN = 2990000;

Int P, Q;
int pri[MAXN], pal[MAXN];
bool p[MAXN];

void sieve() {
	for (Int i = 2; i < MAXN; i++) {
		if (!p[i]) {
			pri[i] = 1;

			for (Int j = i * i; j < MAXN; j += i) {
				p[j] = true;
			}
		}
	}
}

bool isPal(int x) {
	string as_s = "";

	while (x > 0) {
		as_s += '0' + (x % 10);
		x /= 10;
	}
	for (int i = 0; i < (int) as_s.size(); i++) {
		if (as_s[i] != as_s[as_s.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main(void) {
	cin >> P >> Q;

	Int gp = gcd(P, Q);

	P /= gp;
	Q /= gp;
	
	int ans = -1;

	sieve();
	
	for (int i = 1; i < MAXN; i++) {
		pal[i] = isPal(i);

		pri[i] += pri[i - 1];
		pal[i] += pal[i - 1];

		Int g = gcd(pri[i], pal[i]);

		Int u = pri[i] / g;
		Int v = pal[i] / g;

		Int base = lcm(Q, v);

		Int tA = (base / Q) * P;
		Int tB = (base / v) * u;

		if (tA >= tB) {
			ans = i;
		}
	}

	if (ans == -1) {
		cout << "Palindromic tree is better than splay tree\n";
	} else {
		cout << ans << "\n";
	}
	
	return 0;
}
