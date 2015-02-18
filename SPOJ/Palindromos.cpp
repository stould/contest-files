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
string S, R;

int main(void) {
	while (cin >> S) {
		N = (int) S.size();
		R = S;
		
		reverse(R.begin(), R.end());
		
		vector<int> T(N + 10, -1);
		
		for(int i = 1; i <= N; i++) {
			int pos = T[i - 1];
			while(pos != -1 && R[pos] != R[i - 1]) pos = T[pos];
			T[i] = pos + 1;
		}
		
		int sp = 0;
		int kp = 0;
		
		while (sp < N) {
			while (kp != -1 && (kp == N || R[kp] != S[sp])) kp = T[kp];
			kp++;
			sp++;
		}
		cout << N - kp << "\n";
	}

    return 0;
}

