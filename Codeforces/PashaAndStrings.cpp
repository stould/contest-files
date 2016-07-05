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

const int MAXN = 200005;

string S;
int N, M;
int P[MAXN];

int main(void) {
	cin >> S >> N;

	int L = S.size();

	for (int i = 0; i < N; i++) {
		cin >> M;

		M -= 1;

		P[M] += 1;
		P[L - M - 1] -= 1;
	}

	int sum = 0;
	
	for (int i = 0; i < L / 2; i++) {
		sum += P[i];

		if (sum % 2 == 1) {
			swap(S[i], S[L - i - 1]);
		}
	}
	
	cout << S << endl;
	
    return 0;
}
