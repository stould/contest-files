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

int N;
int ap;
map<string, int> mp, cnt;
map<int, string> up;
string A, B;

int func(string s) {
	if (mp[s] == 0) {
		mp[s] = ap;
		up[ap] = s;
		ap++;
	}
}

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		ap = 1;
		mp.clear();
		up.clear();
		for (int i = 0; i < N; i++) {
			cin >> A >> B;
			func(B);
			cnt[B] += 1;
		}
		for (int i = 1; i < ap; i++) {
			cout << up[i] << " " << cnt[up[i]] << "\n";
		}
	}
    return 0;
}
