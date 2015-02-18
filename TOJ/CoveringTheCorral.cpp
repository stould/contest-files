#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <set>
#include <climits>

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

const int MAXN = 100004;
const int INF = INT_MAX / 3;

Int A, B;
int C, M;
int next[MAXN];

int main(void) {
	C = in();
	M = in();

	vector<pair<Int, Int> > P, P_buff;

	for (int i = 0; i < M; i++) {
		scanf("%lld%lld", &A, &B);
		if (B >= C) {
			printf("1\n");
			return 0;
		}
		P.push_back(make_pair(A, A + B));
	}
	sort(P.begin(), P.end());
	
	vector<bool> unuseful(M, false);

	for (int i = 0; i < M; i++) {
		int j = (i + 1) % M;
		int cnt = 0;

		while (cnt < M) {
			if (P[i].first < P[j].first && P[j].second <= P[i].second) {
				unuseful[j] = true;
			} else if (P[j].first < P[i].first && P[i].second % C >= P[j].second % C){	
				unuseful[j] = true;
			} else {
				break;
			}
			j = (j + 1) % M;
			cnt += 1;
		}		
	}

	for (int i = 0; i < M; i++) {
		if (!unuseful[i]) {
			P_buff.push_back(P[i]);
		}
	}

	P = P_buff;
	M = (int) P.size();


	for (int i = 0; i < M; i++) {
		int j = (i + 1) % M, pos = i;
		Int ed = P[i].second % (Int) C;	


		while ((P[j].first <= ed) || (ed < P[i].first && P[j].first > P[i].first)) {
			if (j == i || (j == 0 && P[i].second < C)) {
				break;
			}
			pos = j;
			j = (j + 1) % M;
		}
		next[i] = pos;
	}

	
	int ans = 10101010, f = next[0];

	for (int i = 0; i < f; i++) {
		int used = 0, pos = i;
		set<int> ct;
		while (!ct.count(pos)) {
			used += 1;
			if (P[pos].second % C >= P[i].first && P[pos].second >= C) break;
			ct.insert(pos);
			pos = next[pos];			
		}
		ans = min(ans, used);
	}
	cout << ans << endl;
    return 0;
}
