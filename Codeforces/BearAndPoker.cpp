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
typedef unsigned uint;

const int MAXN = 100005;

int N;
Int P[MAXN];
int p[MAXN];
vector<int> primes;

vector<pair<int, int> > fac(Int x) {
	vector<pair<int, int> > ans;
	
	for (int i = 0; i < (int) primes.size(); i++) {
		if (x % primes[i] == 0) {
			int cnt = 0;

			while (x % primes[i] == 0) {
				x /= primes[i];
				cnt += 1;
			}
			if (primes[i] > 3) {
				ans.push_back(make_pair(primes[i], cnt));
			}
		}
	}

	if (x != 1) {
		ans.push_back(make_pair(x, 1));
	}
	
	return ans;
}

int main(void) {
	cin >> N;

	int sq = (int) sqrt(1000000000) + 1;
	
	for (Int i = 2; i * i <= sq; i++) {
		if (!p[i]) {
			primes.push_back(i);
			
			for (int j = i * i; j <= sq; j += i) {
				p[j] = true;
			}
		}
	}

	set<vector<pair<int, int> > > s;
	
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		s.insert(fac(P[i]));
	}

	if (s.size() == 1) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	
	return 0;
}
