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
const Int INF = 1001010010100010LL;

int N, A, CF, CM;
Int M;
pair<Int, int> P[MAXN];
Int C_SUM[MAXN];

pair<bool, int> can(Int val, int highest_pos, Int available) {
	if (highest_pos < 0) return make_pair(true, 0);

	int l = 0, h = highest_pos, m;
	int best = -1;
	
	while (l <= h) {
		m = (l + h) / 2;
		
		if (P[m].first > val) {
			h = m - 1;
		} else {		
			best = max(best, m);
			l = m + 1;
		}
	}
	
	if (best == -1 || !((best + 1) * val - C_SUM[best] <= available)) {
		return make_pair(false, -1);
	} else {
		return make_pair(true, best);
	}
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main(void) {
    cin >> N >> A >> CF >> CM >> M;

    for (int i = 0; i < N; i++) {
        cin >> P[i].first;
        P[i].second = i;
    }

    sort(P, P + N);
    
    for (int i = 0; i < N; i++) {
		C_SUM[i] = P[i].first;
		
		if (i != 0) {
			C_SUM[i] += C_SUM[i - 1];
		}
    }

	Int used = 0;
	int best_pos = -1;
	Int best_min = -1;
	Int best = -1;
	
	for (int i = N; i >= 0; i--) {
		if (i < N) {
			used += A - P[i].first;		
		}

		if (used > M) break;

		Int l = P[0].first, h = A, m;
		Int local_min = P[0].first;

		//bs on the largest minimum value possible
		while (l <= h) {
			m = (l + h) / 2;
			
			if (can(m, i - 1, M - used).first) {
				local_min = m;
				l = m + 1;
			} else {
				h = m - 1;
			}
		}
		
		Int curr = CF * (N - i) + local_min * CM;

		if (best < curr) {
			best = curr;
			best_min = local_min;
			best_pos = i;
		}
	}
	for (int i = N - 1; i >= best_pos; i--) {
		P[i].first = A;
	}
	
	for (int i = 0; i < N; i++) {
		if (P[i].first > best_min) break;
		P[i].first = best_min;
	}

	cout << best << "\n";
	
	sort(P, P + N, cmp);
	
	for (int i = 0; i < N; i++) {
		cout << P[i].first << " ";
	}
	cout << "\n";
    
	return 0;
}
