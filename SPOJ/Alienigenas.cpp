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

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	for ( ; cin >> N && N != 0; ) {
		set<string> s;
		for (int i = 0; i < N; i++) {
			string S;
			cin >> S;
			sort(S.begin(), S.end());
			s.insert(S);
		}
		cout << s.size() << "\n";
	}	
    return 0;
}
