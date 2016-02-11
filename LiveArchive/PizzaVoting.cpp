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

int N, P;
int V[MAXN], seen[MAXN];
string S[MAXN];

int main(void) {
	cin >> N >> P;

	P -= 1;
	
	for (int i = 0; i < N; i++) {
		cin >> V[i];
	}

	int l = 0, h = N - 1;
	
	for (int i = 0; i < N - 1; i++) {
		if (l > h) break;
		if (i % 3 == 0) {
			seen[h] = true;
			h -= 1;
		} else if (i % 3 == 1) {
			seen[l] = true;
			l += 1;
		} else {
			if (abs(P - l) >= abs(P - h)) {
				seen[l] = true;
				l += 1;
			} else {
				seen[h] = true;
				h -= 1;
			}
		}
	}

	if (!seen[P]) {
		cout << "YES\n";
	} else {
		cout << "NO\n";			
	}
	return 0;
}
