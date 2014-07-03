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

const int MAXN = 1005;

int sum[MAXN];

void build(void) {
	//	set<int> h_p;
	map<int, int> cnt;

	for (int i = 1; 4 * i + 1 < MAXN; i++) {
		for (int j = 1; j < i; j++) {			
			int h = (4 * i + 1) * (4 * j + 1);
			if (h > MAXN) break;
			cnt[h] += 1;
		}
	}
	vector<int> hp;
	map<int, int>::iterator it;
	
	for (it = cnt.begin(); it != cnt.end(); it++) {
		if (it->second == 1) {
			hp.push_back(it->first);
		}
	}
	for (int i = 1; i < MAXN; i++) {
		bool ok = false;
		for (int j = 0; hp[j] <= i; j++) {
			cout << i << " " << hp[j] << " " << i / hp[j] << "\n";
			if (i % hp[j] != 0) continue;
			if (binary_search(hp.begin(), hp.end(), i / hp[j])) {
				ok = true;
				break;
			}
		}
		if (ok) {
			sum[i] += 1;
			sum[i] += sum[i - 1];
		}
				
	}
}

int main(void) {
	build();
	int N;
	for ( ; scanf("%d", &N) && N != 0; ) {
		printf("%d %d\n", N, sum[N]);
	}
    return 0;
}
