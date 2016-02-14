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
const int MAX_BLOCK = 320;

int N, Q;
int P[MAXN], normalize[MAXN];
Int ans[MAXN];
Int tree[MAXN];
map<int, int> memo;
vector<pair<pair<int, int>, int> > block[MAX_BLOCK + 10];
vector<pair<pair<int, int>, int> > inter;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.first.first / MAX_BLOCK != b.first.first / MAX_BLOCK) {
		return a.first.first / MAX_BLOCK < b.first.first / MAX_BLOCK;
	}
	return a.first.second < b.first.second;
}

Int sum(int id) {
	Int ans = 0;

	for (int i = id; i > 0; i -= i & -i) {
		ans += tree[i];
	}
	
	return ans;
}

void update(int id, int val) {
	if (id <= 0) return;
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
	
	for (int i = 0; i < Q; i++) {
		int A, B;
		
		cin >> A >> B;

		A -= 1;
		B -= 1;
		
		inter.push_back(make_pair(make_pair(A, B), i));
	}
	
	sort(inter.begin(), inter.end(), cmp);

	for (int i = 0; i < Q; i++) {
		block[inter[i].first.first / MAX_BLOCK].push_back(inter[i]);
	}

	for (int i = 0; i < MAX_BLOCK; i++) {
		if (block[i].empty()) {
			break;
		}
		int l = block[i][0].first.first;
		int r = block[i][0].first.first;

		memset(tree, 0, sizeof(tree));

		update(P[l], 1);
		
		Int curr_ans = 0;
		
		for (int j = 0; j < (int) block[i].size(); j++) {
			while (l < block[i][j].first.first) {
				Int gt = sum(P[l] - 1);
				curr_ans -= gt;
				update(P[l], -1);
				l += 1;
			}

			while (l - 1 >= block[i][j].first.first) {
				l -= 1;
				Int gt = sum(P[l] - 1);
				curr_ans += gt;				
				update(P[l], 1);
			}
			
			while (r + 1 <= block[i][j].first.second) {
				r += 1;
				curr_ans += (sum(base) - sum(P[r]));
				update(P[r], 1);
			}
			ans[block[i][j].second] = curr_ans;
		}		
	}	

	for (int i = 0; i < Q; i++) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}
