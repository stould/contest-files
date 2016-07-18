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

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int main(void) {
    return 0;
}
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

int T, N;

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		vector<int> px, py;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 4; j++) {
				int X, Y;
				cin >> X >> Y;
				
				px.push_back(X);
				py.push_back(Y);
			}
		}

		sort(px.begin(), px.end());
		sort(py.begin(), py.end());

		Int ans = (px[px.size() - 1] - px[0]) * (py[py.size() - 1] - py[0]);

		cout << ans << "\n";
	}
	return 0;
}
