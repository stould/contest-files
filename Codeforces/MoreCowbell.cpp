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

const int MAXN = 100010;

int N, K;
int P[MAXN];
int B[MAXN];

int main(void) {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	sort(P, P + N);
	reverse(P, P + N);
	
	for (int i = 0; i < K; i++) {
		B[i] = P[i];
	}

	int s = K - 1;
	
	for (int i = K; i < N; i++) {
		B[s--] += P[i];
	}

	cout << *max_element(B, B + K) << "\n";
	
	return 0;
}
