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

const int MAXN = 200007;

int N;
int A[MAXN];

/*
  if a cow is to the left, then, all the right cows before it will get scared, 
  else, we count this right cow.
*/

int main(void) {
	N = in();

	Int ans = 0LL;

	for (int i = 0; i < N; i++) {
		A[i] = in();
	}

	int sum = 0;

	for (int i = 0; i < N; i++) {
		if (A[i] == 1) {
			sum += 1;
		} else {
			ans += sum;
		}
	}

	cout << ans << "\n";
    return 0;
}


