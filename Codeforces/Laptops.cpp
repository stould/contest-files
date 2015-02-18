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
int A[100005], B[100005];

vector<pair<int, int> > vp;

int main(void) {
	cin >> N;

	bool ok = false;

	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
		
		vp.push_back(make_pair(A[i], B[i]));
	}

	sort(vp.begin(), vp.end());

	for (int i = N - 2; !ok && i >= 0; i--) {
		if (vp[i].second > vp[i + 1].second) ok = true;
	}

	if (ok) {
		cout << "Happy Alex\n";
	} else {
		cout << "Poor Alex\n";
	}
    return 0;
}
