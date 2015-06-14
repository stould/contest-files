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

const int MAXN = 110;

int N, M;
int P[MAXN], L[MAXN], R[MAXN], C[MAXN];
int A[MAXN], B[MAXN];

vector<pair<int, int> > Pid;

bool fine() {
	bool ok = true;

	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (L[i] <= Pid[j].first && R[i] >= Pid[j].first) {
				if (C[Pid[j].second] == 0) {
					A[i] += 1;
				} else {
					B[i] += 1;
				}
			}
		}
	}
	
	for (int i = 0; i < M; i++) {
		if (abs(A[i] - B[i]) > 1) {
			ok = false;
		}
	}
	
	return ok;
}

int main(void) {
	cin >> N >> M;
	
	
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		
		Pid.push_back(make_pair(P[i], i));
	}
	
	sort(Pid.begin(), Pid.end());

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			C[Pid[i].second] = 1;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> L[i] >> R[i];
	}

	if (!fine()) {
		for (int i = 0; i < N; i++) {
			C[Pid[i].second] ^= 1;
		}
	}
	if (!fine()) {
		cout << "-1" << endl;
	} else {
		for (int i = 0; i < N; i++) {
			cout << C[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
