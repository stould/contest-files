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

const int MAXN = 35;

int N;
string S, P[MAXN];

bool cmp(string a, string b) {
	for (int i = 0; i < min(a.size(), b.size()); i++) {
		int p = S.find(a[i]);
		int q = S.find(b[i]);

		if (p != q) return p < q;
	}
	return a.size() < b.size();
}

int main(void) {
	int t = 1;
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		cin >> S;
		
		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}

		sort(P, P + N, cmp);

		cout << "year " << t++ << "\n";
		for (int i = 0; i < N; i++) {
			cout << P[i] << "\n";
		}
	}
    return 0;
}
