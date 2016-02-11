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
map<int, double> mp;

int main(void) {
	cin >> N;

	mp[1001] = 1.5;
	mp[1002] = 2.5;
	mp[1003] = 3.5;
	mp[1004] = 4.5;
	mp[1005] = 5.5;
	
	double ans = 0.0;

	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		ans += mp[A] * B;
	}
	cout << fixed << setprecision(2) << ans << endl;
	return 0;
}
