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

const int MAXN = 50;

bool done;
int N;
int S[MAXN], A[MAXN];
int ans[MAXN];

void func(int mask, int id, int cnt) {
	if (__builtin_popcount(mask) == 15) {
		if (cnt >= 11) {
			done = true;
		}
		ans[cnt] += 1;
		return;
	}
	if (id >= N) return;
	int add = S[A[id]] > 0;
	func(mask | (1 << id), id + 1, cnt + add);
	func(mask, id + 1, cnt);
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int p, test = 1;

	for (int i = 0; i < 15; i++) {
		cin >> p;
		S[p] += 1;
	}
	
	for ( ; cin >> N; )  {
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		
		done = false;
		func(0, 0, 0);

		cout << "Aposta " << test++ << "\n";

		if (!done) {
			cout << "nenhum premio aqui\n";
		} else {
			for (int i = 11; i <= 15; i++) {
				if (ans[i] > 0) {
					cout << i << ": " << ans[i] << "\n";
				}
			}
		}
		cout << "\n";
		for (int i = 0; i < MAXN; i++) {
			A[i] = ans[i] = 0;
		}
	}
    return 0;
}
