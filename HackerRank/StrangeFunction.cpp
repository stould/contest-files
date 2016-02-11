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

int N, M;
Int A[MAXN], P[MAXN];

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		P[i] = A[i];
	}

	sort(A, A + N);

	map<int, int> pos;

	for (int i = 0; i < N; i++) {
		pos[A[i]] = i;
	}

	for (int i = 0; i < N; i++) {
		if (pos[P[i]] >= N / 2) {
			P[i] += M;
		} else {
			P[i] -= M;
		}
	}
	
	sort(P, P+ N);

	Int ans = 0;
	Int sum = 0;
	
	for (int i = 0; i < N; i++) {
		ans += abs((P[i] * i) - sum);
		sum += P[i];
	}
	
	cout << ans << "\n";
	
	return 0;
}
