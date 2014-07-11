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

int N, P;

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		scanf("%d", &P);

		int p = 1, q = N;

		for (int i = 0; i < N / 3; i++) {
			vector<int> ps;
			ps.push_back(p);
			ps.push_back(p + 1);
			ps.push_back(q - 1);
			ps.push_back(q);
			
			if (find(ps.begin(), ps.end(), P) != ps.end()) {
				bool ok = false;
				for (int j = 0; j < 4; j++) {
					if (ps[j] != P) {
						if (ok) {
							printf(" ");
						}

						printf("%d", ps[j]);
						ok = true;
					}					
				}
				printf("\n");
				break;
			}
			p += 2;
			q -= 2;
		}
	}
    return 0;
}
