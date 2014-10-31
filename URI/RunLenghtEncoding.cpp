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

int main(void) {
	for ( ; cin >> S; ) {	
		int N = (int) S.size();
		
		for (int i = 0; i < N; i++) {
			int j = 0;
			if (i + 1 < N && S[i + 1] == S[i]) {
				for ( ; j < 9 && i + j < N && S[i] == S[i + j]; ) {
					j++;
				}
				cout << ((i + j) - i) << "" << S[i]	;			
				i = i + j - 1;
			} else {
				j = i + 1;
				cout << 1;
				for ( ; S[j] != S[j - 1]; ){
					cout << S[j - 1];
					j++;
				}
				cout << 1;
				i = j;
			}
		}
		cout << "\n";
	}
    return 0;
}
