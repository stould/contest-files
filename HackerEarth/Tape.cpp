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

int N, K, D;
int P[MAXN];

int main(void) {
	cin >> N >> K >> D;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	Int s = 0;
	int ans = 0;
	
	for (int i = 0; i < K; i++) {
		s += P[i];
	}

	bool gone = false;
	
	for (int i = K; i < N; i++) {
		if (s == 0) {
			ans = -1;
			break;
		} else {
			if (s >= D) {
				s += P[i];
				s -= P[i - K];
			} else {
				ans += 1;
				
				for (int j = 0; j < K; j++) {
					
				}
			}
		}
	}
	
	if (!gone) {
		if (s == 0) {
			ans = -1;
		} else if (s <= D) {
			ans += 1;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
