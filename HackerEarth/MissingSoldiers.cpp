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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;

int N;
pair<int, int> P[MAXN];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int PX, PY, PD;
		
		cin >> PX >> PY >> PD;

		P[i] = make_pair(PX, PX + PD);
	}

	sort(P, P + N);

	vector<pair<int, int> > ed;
	int ans = 0;

	for (int i = 0; i < N; i++) {
		int bi = P[i].first;
		int bj = P[i].second;

		int j = i;

		while (j < N) {
			if (P[j].first > bj) break;
			chmax(bj, P[j].second);
			j++;			
		}

		while (j < N && P[j].first <= bj) j++;
		
		ed.push_back(make_pair(bi, bj));

		i = j - 1;
	}


	for (int i = 0; i < (int) ed.size(); i++) {
		//cout << ed[i].first << " " << ed[i].second << endl;
		ans += ed[i].second - ed[i].first + 1;
	}

	cout << ans << "\n";
	
	return 0;
}
