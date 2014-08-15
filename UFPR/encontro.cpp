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

int N, M, P;
int V, W;

void process(int pos, int& x, int& y) {
	if (pos == 1) {
		y += 1;
	} else if (pos == 2) {
		y -= 1;
	} else if (pos == 3) {
		x += 1;
	} else {
		x -= 1;
	}
}

int main(void) {
	cin >> N >> M >> P;
	int x1 = 1, y1 = 1, x2 = N, y2 = M;

	for (int i = 0; i < P; i++) {
		cin >> V >> W;
		process(V, x1, y1);
		process(W, x2, y2);

		if (x1 < 1 || y1 < 1 || x1 > N || y1 > M) {
			printf("PA saiu na posicao (%d,%d) no passo %d\n", x1, y1, i + 1);
			return 0;
		} else if (x2 < 1 || y2 < 1 || x2 > N || y2 > M) {
			printf("PB saiu na posicao (%d,%d) no passo %d\n", x2, y2, i + 1);
			return 0;
		} else if (x1 == x2 && y1 == y2) {
			printf("Encontraram-se na posicao (%d,%d) no passo %d\n", x1, y1, i + 1);
			return 0;			
		}	   
	}
	printf("Nao se encontraram\n");
    return 0;
}
