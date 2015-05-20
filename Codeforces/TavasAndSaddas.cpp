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
vector<Int> lucky;

void gen(Int x) {
	if (x > 1000000000) {
		return;
	}
	lucky.push_back(x);
	gen(x * 10 + 4);
	gen(x * 10 + 7);
}

int main(void) {
	gen(0);

	sort(lucky.begin(), lucky.end());
	
	int l = 0, h = (int) lucky.size() - 1, m;

	cin >> N;

	while (l <= h) {
		m = (l + h) / 2;

		if (lucky[m] == N) {
			cout << m << endl;
			break;
		} else if (lucky[m] < N) {
			l = m + 1;
		} else {
			h = m - 1;
		}
	}
		
	return 0;
}
