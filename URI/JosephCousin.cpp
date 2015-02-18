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

const int MAX_P = 1010101;

int N;
vector<int> primes;

void build(void) {
	bool b[MAX_P];

	fill(b, b + MAX_P, true);

	for (int i = 2; i < MAX_P; i++) {
		if (b[i]) {
			for (int j = i * i; j > 0 && j < MAX_P; j += i) {
				b[j] = false;
			}
			primes.push_back(i);
		}
	}
}

int func(int x) {
	vector<int> vs(x);
	for (int i = 0; i < x; i++) {
		vs[i] = i;
	}
	int pos = 0, id = 0;
	for (int i = 0; i < x - 1; i++) {
		int next = (pos + primes[id++] - 1) % ((int) vs.size());
		vs.erase(vs.begin() + next);
		pos = next;
	}
	return vs[0] + 1;
}

int main(void) {
	build();
	cout << primes.size() << "\n";
	for ( ; cin >> N && N != 0; ) {
		cout << func(N) << "\n";
	}
    return 0;
}
