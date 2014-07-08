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

const double EPS = 1e-7;

int N, P, Q;

bool cp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main(void) {
	int t = 1;
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		if (t > 1) printf("\n");
		printf("Cidade# %d:\n", t++);
		
		vector<pair<int, int> > bp;
		double sum = 0.0, cnt = 0.0;
		map<int, int> mp;
		map<int, int>::iterator it;

		for (int i = 0; i < N; i++) {
			scanf("%d%d", &P, &Q);
			sum += Q;
			cnt += P;
			mp[Q / P] += P;			
		}
		for (it = mp.begin(); it != mp.end(); it++) {
			bp.push_back(make_pair(it->second, it->first));			
		}
		sort(bp.begin(), bp.end(), cp);
		for (int i = 0; i < bp.size(); i++) {
			if (i > 0) printf(" ");
			printf("%d-%d", bp[i].first, bp[i].second);
		}
		printf("\nConsumo medio: %.2lf m3.\n", (double) ((int) (sum / cnt * 100.0 + EPS) / 100.0));
	}
    return 0;
}
