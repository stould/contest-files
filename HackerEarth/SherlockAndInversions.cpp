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

const int MAXN = 200005;
const int MAX_BLOCK = 3000;

int N, Q;
int P[MAXN], normalize[MAXN];
Int ans[MAXN];
int tree[MAXN];
map<int, int> memo;
vector<pair<pair<int, int>, int> > block[MAX_BLOCK];

Int sum(int id) {
	Int ans = 0;

	for (int i = id; i > 0; i -= i & -i) {
		ans += tree[i];
	}
	
	return ans;
}

void update(int id, int val) {
	for (int i = id; i <= N; i += i & -i) {
		tree[i] += val;
	}
}

int main(void) {
	cin >> N >> Q;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
		normalize[i] = P[i];
	}

	sort(normalize, normalize + N);

	int base = 1;

	for (int i = 0; i < N; i++) {
		if (memo[normalize[i]] == 0) {
			memo[normalize[i]] = base++;
		}
	}

	for (int i = 0; i < N; i++) {
		P[i] = memo[P[i]];
	}
	
	int sq = (int) sqrt(N + 1);
	
	for (int i = 0; i < Q; i++) {
		int A, B;
		
		cin >> A >> B;

		A -= 1;
		B -= 1;
		
		block[A / sq].push_back(make_pair(make_pair(A, B), i));
	}

	for (int i = 0; i < MAX_BLOCK; i++) {
		if (!block[i].empty()) {
			sort(block[i].begin(), block[i].end());

			int l = block[i][0].first.first;
			int r = block[i][0].first.first;
			
			memset(tree, 0, sizeof(tree));

			Int curr_ans = 0;
			
			for (int j = 0; j < (int) block[i].size(); j++) {
				while (r > block[i][j].first.second) {
					curr_ans -= (sum(base) - sum(P[r]));					
					update(P[r], -1);
					r -= 1;
				}				

				while (l < block[i][j].first.first) {
					Int gt = sum(P[l] - 1);
					curr_ans -= gt;
					update(P[l], -1);
					l += 1;
				}
				while (r <= block[i][j].first.second) {
					curr_ans += (sum(base) - sum(P[r]));
					update(P[r], 1);
					r += 1;
				}
				ans[block[i][j].second] = curr_ans;
			}
		}	
	}

	for (int i = 0; i < Q; i++) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}
