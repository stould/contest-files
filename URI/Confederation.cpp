#include <bits/stdc++.h>

using namespace std;

const int MAXN = 550;
const int MAXM = 10010;

int N, M;
int X[MAXM], Y[MAXM], Z[MAXM];

struct Plane {
  int a, b, c, d;
};

Plane P[MAXN];

//Position of point index about Plane p;
char sign(Plane p, int index) {
	long long eq = p.a * X[index] + p.b * Y[index] + p.c * Z[index] - p.d;
	
  if (eq < 0) return '0';
  return '1';
}

int main(void) {
	for ( ; scanf("%d%d", &N, &M) == 2; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d%d%d%d", &P[i].a, &P[i].b, &P[i].c, &P[i].d);
		}
		
		map<string, int> check;
		int best = 0;
		
		for (int i = 0; i < M; i++) {
			scanf("%d%d%d", &X[i], &Y[i], &Z[i]);
			
			string sp = "";
			
			for (int j = 0; j < N; j++) {
				sp += sign(P[j], i);
			}
			
			check[sp] += 1;
			best = max(best, check[sp]);
		}
		
		printf("%d\n", best);
	}
	return 0;
}
