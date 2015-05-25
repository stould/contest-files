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

int Q, E;
int M[1010];

int main(void) {
	cin.tie(0);
	
	cin >> Q >> E;

	for (int i = 0; i < E; i++) {
		int a;
		cin >> a;
		M[a] = 1;
	}

	for (int i = 0; i < Q; i++) {
		int a;
		cin >> a;
		
		if (M[a]) {
			cout << "0" << endl;
		} else {
			cout << "1" << endl;
		}
		M[a] = 1;
	}
	return 0;
}
