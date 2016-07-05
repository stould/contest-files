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
int p[10005];

int main(void) {
	cin >> N;

	
	set<int> seen;
	
	for (int i = 2; i <= N; i++) {
		if (!p[i]) {
			for (int j = i * i; j <= N; j += i) {
				p[j] = true;
			}
			for (int j = i; j <= N; j *= i) {
				seen.insert(j);
			}
		}
	}

	cout << seen.size() << endl;

	for (auto& i: seen) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
