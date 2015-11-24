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

int main(void) {
	cin >> N;

	Int ans = 0LL, sum = 0;
	int curr;
	map<Int, Int> cnt;
	
	for (int i = 0; i < N; i++) {
		cin >> curr;

		sum += curr;
		
		if (curr == 0) {
			ans += 1;
		}
		//cout << sum << " ";
		cout << sum << " " << cnt[sum] << "\n";
		ans += cnt[sum];
		cnt[sum] += 1;
	}
	cout <<" \n";
	cout << ans <<"\n";
	
	return 0;
}
