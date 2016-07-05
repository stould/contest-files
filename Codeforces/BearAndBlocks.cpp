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
const Int INF = 10010010100100LL;

int N;
Int P[MAXN];
Int rem[MAXN];

void gen() {
	cout << 100000 << "\n";

	srand(time(NULL));
	for (int i = 0; i < 100000; i++) {
		cout << (Int) (rand() * 1000000000LL) << " ";
	}
	cout << "\n";
}

int main(void) {	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
		rem[i] = INF;
	}

	rem[0] = rem[N - 1] = 1;
	
	while (true) {
		bool seen = false;
		for (int i = 1; i < N; i++) {
			if (rem[i] > min(rem[i - 1] + 1, P[i])) {
				rem[i] = min(rem[i - 1] + 1, P[i]);
				seen = true;
			}
		}
		for (int i = N - 2; i >= 0; i--) {
			if (rem[i] > min(rem[i + 1] + 1, P[i])) {
				rem[i] = min(rem[i + 1] + 1, P[i]);
				seen = true;
			}
		}
		if (!seen) break;
		//if (ans == last) break;
	}

	cout << *max_element(rem, rem + N) << "\n";
	return 0;
}
