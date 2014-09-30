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

int N, A, B;
int P[MAXN];
int used[MAXN];
set<int> S;
unordered_map<int, int> pos;
bool good;

void dfs(int x, int s) {
	used[x] = s;

	int v = P[x];
	int o = s == 1 ? A : B;

	if (S.count(o - v)) {

		int p = pos[o - v];
		
		if (used[p] == s) {
			return;
		}
		dfs(p, s);
	} else {
		good = false;
	}
}

int main(void) {
	scanf("%d%d%d", &N, &A, &B);

	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
		pos[P[i]] = i;
		S.insert(P[i]);
	}
	
	bool ok = true;
	good = true;

	for (int i = 0; ok && i < N; i++) {     
		if (A - P[i] <= 0 && B - P[i] <= 0) {
            ok = false;
        } else if (!used[i]) {
            bool onA = false, onB = false;
			
            if (S.count(A - P[i])) {
                onA = true;
            }
            if (S.count(B - P[i])) {
                onB = true;
            }

			if (onA && onB) {
				dfs(i, 2);
			} else if (onA) {
				used[pos[P[i]]] = used[pos[A - P[i]]] = 1;
			} else if (onB) {
				used[pos[P[i]]] = used[pos[B - P[i]]] = 2;
			} else {
				ok = false;
			}
        }
    }

	if (!ok) {
		puts("NO");
	} else {
		puts("YES");

		for (int i = 0; i < N; i++) {
			printf("%d ", used[i] - 1);
		}
		printf("\n");
	}
	
    return 0;
}
