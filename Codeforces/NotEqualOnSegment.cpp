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

int N, M;
int P[MAXN];

static unsigned int x=123456789, y=362436069, z=521288629;

unsigned int xorshf96(void) {
	int long t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
	
	t = x;
	x = y;
	y = z;
	z = t ^ x ^ y;
	
	return z;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
	}

	for ( ; M--; ) {
		int A, B, C;
		
		scanf("%d%d%d", &A, &B, &C);

		A -= 1;
		B -= 1;

		bool ok = false;
		
		for (int i = 0; i < max(400, (B - A + 1) / 100); i++) {
			int curr = (xorshf96() % (B - A + 1));
			
			if (P[A + curr] != C) {
				printf("%d\n", A + curr + 1);
				ok = true;
				break;
			}
		}

		if (!ok) {
			printf("-1\n");
		}
	}

	return 0;
}
