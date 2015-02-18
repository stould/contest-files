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

const int MAXN = 40010;

int N;
int pr[MAXN];
bool sit[MAXN];

int main(void) {
	int id = 0;
	memset(sit, true, sizeof(sit));

	for (int i = 2; i < MAXN; i++) {
		if (sit[i]) {
			int cnt = 0;
			for (int j = i + 1; j < MAXN; j++) {
				if (sit[j]) {
					cnt++;
					if (cnt % i == 0) {
						sit[j] = false;					
					}
				}
			}
		}
	}
	for (int i = 2; i < MAXN; i++) {
		if (sit[i]) {
			pr[id++] = i;
		}
	}
	for ( ; cin >> N && N != 0; ) {
		cout << pr[N-1] << "\n";
	}
    return 0;
}
