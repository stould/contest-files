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

int T, N;
int A[12], B[12], C[12];

double func(int id) {
	double x = (B[id]/(2.0 * A[id]));
	
	double ans = -A[id] * x * x + B[id] * x + C[id];

	return ans;
}

int main(void) {
	cin >> T;
	
	for ( ; T--; ) {
		cin >> N;

		double value = 0.0;
		int id = -1;

		for (int i = 0; i < N; i++) {
			cin >> A[i] >> B[i] >> C[i];
			
			double curr = func(i);

			if (curr > value) {
				value = curr;
				id = i + 1;
			}
		}

		cout << id << "\n";
	}

    return 0;
}
