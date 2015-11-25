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

int base[MAXN];
int N;

int main(void) {
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> base[i];
	}
	int low = 0, big = 0;
	int ans = 1;
	for(int i = 1; i < N; i++){
		if(base[i] < base[low]){
			low = i;
		}
		if(base[i] > base[big]){
			big = i;
		}
		while(abs(base[i] - base[low]) > 1){
			low++;
		}
		while(abs(base[i] - base[big]) > 1){
			big++;
		}
		ans = max(ans, i - min(low, big)  + 1);
	}
	cout << ans << endl;
	return 0;
}
