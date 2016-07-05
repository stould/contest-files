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

int N, P;
string S;

int rel(int pos) {
	return N - pos - 1;
}

int dist(char a, char b) {
	int pa = a - 'a';
	int pb = b - 'a';
	
	return min(abs(pa - pb), 26 - abs(pa - pb));
}

int main(void) {
	cin >> N >> P >> S;

	P -= 1;
	
	if (P >= N / 2) {
		P = rel(P);
	}
	
	int l = -1;
	int r = -1;

	int ans = 0;
	
	for (int i = 0; i < (int) N / 2; i++) {
		if (S[i] != S[rel(i)]) {
			ans += dist(S[i], S[rel(i)]);
			
			if (l == -1) {
				l = i;
			}			
			r = i;		
		}
	}

	if (r != -1) {
		ans += r - l;
		
		ans += min(abs(r - P), abs(P - l));
	}

	cout << ans << "\n";
	
	return 0;
}
