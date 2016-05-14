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

int N;
int P[30];
bool ok;
Int ans;

void func(int pos, set<int> used, Int val) {
	if (pos < 0) {
		ok = true;
		ans = val;
	} else {
		int cnt = 0;
		
		for (int i = P[pos]; i >= 0 && cnt < 5; i--) {
			if (!used.count(i)) {
				cnt += 1;
				set<int> other = used;
				other.insert(i);
				
				func(pos - 1, other, val + i);
				
				if (ok) return;
			}
		}

		func(pos - 1, used, val);
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	sort(P, P + N);

	func(N - 1, set<int>(), 0);
	
	cout << ans << "\n";
	
	return 0;
}
