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

int A, B;
int cnt[10];

int func(int x) {
	if (x == 0) return 6;

	int ans = 0;

	while (x > 0) {
		ans += cnt[x % 10];
		x /= 10;
	}
	return ans;
}

int main(void) {
	cin >> A >> B;
	
	cnt[0] = 6;
	cnt[1] = 2;
	cnt[2] = 5;
	cnt[3] = 5;
	cnt[4] = 4;
	cnt[5] = 5;
	cnt[6] = 6;
	cnt[7] = 3;
	cnt[8] = 7;
	cnt[9] = 6;

	int ans = 0;

	for (int i = A; i <= B; i++) {
		ans += func(i);
	}

	cout << ans << endl;

	return 0;
}
