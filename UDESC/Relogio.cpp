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
char a[3], b[3];
string A[60], B[60];
bool match[10][10];

void build(void) {
	memset(match, false, sizeof(match));

	for (int i = 0; i < 10; i++) match[i][i] = true;
	
	match[0][8] = match[8][0] = true;
	match[1][3] = match[1][4] = match[1][7] = match[1][8] = match[1][9] = true;
	match[2][0] = match[2][8] = true;
}
		
bool func(int x) {
	
}

int main(void) {
	build();
	for ( ; scanf("%d", &N) == 1; ) {
		for (int i = 0; i < N; i++) {
			scanf("%s:%s", a, b);
			A[i] = string(a);
			B[i] = string(b);
		}
		vector<pair<string, string> > ans;
		for (int i = 0; i < 24 * 60; i++) {
			int h  = i / 24, m = i % 24;
			int d0 = (h / 10) % 10;
			int d1 = h % 10;
			int d2 = (m / 10) % 10;
			int d3 = m % 10;

			if (match[d0][A[0][0] - '0'] && match[d1][A[0][1] - '0'] && match[d2][B[0][0] - '0'] && match[d3][B[0][1] - '0']) {
				bool ok = true;
				for (int j = 1; j < N; j++) {
					if (!func(i + j)) {
						ok = false;
					}
				}
				if (ok) {
					string sh = "", sm = "";
					sh += d0 + '0';
					sh += d1 + '0';
					sm += d2 + '0';
					sm += d3 + '0';
					ans.push_back(make_pair(sh, sm)));
				}
			}
		}
		if (ans.empty()) {
			printf("NENHUM\n");
		} else {
			sort(ans.begin(), ans.end(), cmp);
			for (int i = 0; i < ans.size(); i++) {
				if (i > 0) printf(" ");
				printf("%d:%d", ans[i].first, ans[i].second);
			}
			printf("\n");
		}
	}
    return 0;
}
