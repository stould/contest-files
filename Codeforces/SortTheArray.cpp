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

const int MAXN = 100005;

int N;
int P[MAXN], cpy[MAXN];
map<int, int> nx;

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		cpy[i] = P[i];
	}

	sort(cpy, cpy + N);
	reverse(cpy, cpy + N);

	for (int i = 1; i < N; i++) {
		nx[cpy[i]] = cpy[i - 1];
	}

	bool ok = true;
	
	for (int i = 0; i < N; i++) {
		int j = i + 1;
		
		while (j < N) {
			if (nx[P[j]] != P[j - 1]) break;
			j++;
		}
		if (j != i + 1) {
			reverse(P + i, P + j);
			reverse(cpy, cpy + N);
			for (int k = 0; k < N; k++) {
				if (cpy[k] != P[k]) {
					ok = false;
				}
			}
			if (ok) {
				printf("yes\n%d %d\n", i + 1, j);
			} else {
				puts("no");
			}
			return 0;
		}
	}
	reverse(cpy, cpy + N);

	for (int i = 0; i < N; i++) {
		if (cpy[i] != P[i]) ok = false;
	}
	if (ok) printf("yes\n1 1\n");
	else printf("no\n");
    return 0;
}
