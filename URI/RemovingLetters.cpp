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

string S;
int N;
int M[27][1001];

vector<string> vs;

void build(int pos, string s) {
	if (pos == N) {
		return;
	} else {
		for (int i = 0; i < 26; i++) {
			if (M[i][pos] >= pos) {
				vs.push_back(s + (char) ('a' + i));
				build(M[i][pos] + 1, s + (char) ('a' + i));
			}
		}
	}
}

int main(void) {
	for ( ; cin >> S; ) {
		N = (int) S.size();
		vs.clear();
		memset(M, -1, sizeof(M));

		for (int i = 0; i < N; i++) {
			M[S[i] - 'a'][i] = i;
		}
		for (int i = 0; i < 26; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (M[i][j] != -1) continue;
				M[i][j] = M[i][j + 1];
			}
		}
		build(0, "");
		sort(vs.begin(), vs.end());
		for (int i = 0; i < vs.size(); i++) {
			cout << vs[i] << "\n";
		}
		cout << "\n";
	}
    return 0;
}
