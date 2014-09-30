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
typedef unsigned uint;

const int MAXM = 50005;

int N, K;
int P[MAXM];

int main(void) {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
		P[i] -= 1;
	}
	
	sort(P, P + N);
	reverse(P, P + N);
	
	
	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		int j = i, best = 0;
		
		while (j < N && j - i + 1 <= K) {
			chmax(best, P[j]);
			j++;
		}
		
		ans += best * 2;		
		i = j - 1;
	}
	
	cout << ans << "\n";	
    return 0;
}

