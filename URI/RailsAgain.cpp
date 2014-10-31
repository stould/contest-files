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
char P[30], Q[30];

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		string ans = "";
		
		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}

		for (int i = 0; i < N; i++) {
			cin >> Q[i];
		}
				
		stack<char> s;
		int pos = 0;

		for (int i = 0; i < N; i++) {		
			s.push(P[i]);
			ans += "I";
			
			while (!s.empty() && s.top() == Q[pos]) {
				s.pop();
				pos++;
				ans += "R";
			}
		}

		cout << ans;
		
		if (pos != N) {
			cout << " Impossible\n";
		} else {
			cout << "\n";
		}
	}
    return 0;
}
