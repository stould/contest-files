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

const int MAXN = 1000005;

int N;
int P[MAXN];

int main(void) {
	cin >> N;

	int ans = 0;

	unordered_map<int, int> memo;
	
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		memo[P[i]] += 1;
	}

	if (memo[0] > 0) {
		int p = 1;

		while (p <= memo[0]) {
			p *= 2;
		}
		p /= 2;

		ans += 1 + (memo[0] - p);
	}
	
	set<int> u_buff(P, P + N);
	vector<int> uniq(u_buff.begin(), u_buff.end());

	for (int i = 0; i < (int) uniq.size(); i++) {
		int curr = uniq[i];
		
		if (memo[curr] <= 0 || curr == 0) continue;

		while (memo[curr] > 0) {
			int sum = curr;
			
			ans += 1;
			memo[curr] -= 1;
			
			while (memo[sum] > 0) {
				memo[sum] -= 1;
				sum *= 2;			
			}
		}
	}

	cout << ans << "\n";
	return 0;
}
