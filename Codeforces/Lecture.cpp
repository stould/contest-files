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

int N, M;
map<string, string> chk;
map<string, int> first;

int main(void) {
	cin >> N >> M;

	string A, B;
	
	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		first[A] = 1;

		chk[A] = B;
		chk[B] = A;
	}

	for (int i = 0; i < N; i++) {
		cin >> A;
		B = chk[A];

		if (i > 0) cout << " ";

		
		if (A.size() < B.size() || (A.size() == B.size() && first[A] == 1)) {
			cout << A;
		} else {			
			cout << B;
		}
	}

	cout << "\n";
	
    return 0;
}
