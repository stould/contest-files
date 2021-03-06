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
map<char, char> mp;

int main(void) {
	getline(cin, S);
	
	int N = (int) S.size();

	for (int i = 0; i < N; i++) {
		if ((S[i] >= '0' && S[i] <= '9') || S[i] == '-') {
			cout << S[i];
		} else {
			char c = '$';
			if (S[i] >= 'A' && S[i] <= 'C') {
				c = '2';
			} else if (S[i] >= 'D' && S[i] <= 'F') {
				c = '3';
			} else if (S[i] >= 'G' && S[i] <= 'I') {
				c = '4';
			} else if (S[i] >= 'J' && S[i] <= 'L') {
				c = '5';
			} else if (S[i] >= 'M' && S[i] <= 'O') {
				c = '6';
			} else if (S[i] >= 'P' && S[i] <= 'S') {
				c = '7';
			} else if (S[i] >= 'T' && S[i] <= 'V') {
				c = '8';
			} else if (S[i] >= 'W' && S[i] <= 'Z') {
				c = '9';
			}
			cout << c;
		}
	}
	cout << "\n";
    return 0;
}
