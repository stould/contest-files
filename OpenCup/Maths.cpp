#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1568619;
const int MAX_D = 301;

int N;
int dv[MAXN];
int cp[100001], pos;
bool ok;

void rec(int len, int sum) {
	if (ok) return;
	if (len == N) {
		ok = true;
		return;
	} else {
		for (int i = 300; !ok && i >= 1; i--) {
			if (sum + i < MAXN && dv[sum + i] == i) {
				cp[pos++] = i;
				rec(len + 1, sum + i);
				if (!ok) {
					pos--;
				}
			}
		}
	}
}

int main() {
	scanf("%d", &N);
      
	dv[1] = 1;
  
	for (int i = 2; i < MAXN; i++) {
		dv[i] += 1;
		for (int j = i; j < MAXN; j += i) {
			dv[j] += 1;
		}
	}
  
	ok = false;
	pos = 0;
  
	rec(0, 0);
  
	if (pos == N) {
		int s = 0;
		for (int i = 0; i < N; i++) {
			printf("%d\n", cp[i]);
		}
	} else {
		printf("Impossible\n");
	}

	return 0;
}
