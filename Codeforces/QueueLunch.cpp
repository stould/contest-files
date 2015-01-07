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

map<int, int> pr, nx;

int N;
int A[MAXN], B[MAXN];
int Q[MAXN];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
		
		nx[A[i]] = B[i];
		pr[B[i]] = A[i];

		if (A[i] == 0) {
			Q[1] = B[i];
		}

		if (B[i] == 0) {
			Q[N-2] = A[i];
		}
	}

	Q[0] = pr[Q[1]];
	
	int curr = Q[1], pos = 1;
	
	set<int> seen;

	while (pos < N) {
		Q[pos] = curr;
		pos += 2;
		seen.insert(curr);
		curr = nx[curr];
	}

	for (int i = 0; i < N; i++) {
		if (A[i] != 0 && !seen.count(A[i])) {
			curr = A[i];

			while (pr[curr] != 0) {
				curr = pr[curr];
			}
			
			pos = 0;

			while (pos < N) {
				Q[pos] = curr;
				pos += 2;
				curr = nx[curr];
			}
			break;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << Q[i] << " ";
	}

	cout << "\n";

    return 0;
}
