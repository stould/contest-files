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

const int MAXN = 100005;

int N;
int K;

int x[MAXN];

int func(int pos) {
	int i;
	int ans = x[pos];

	for (i = (pos + K) % N; i != pos; i = (i + K) % N) {
		ans += x[i];		
	}

	return ans;
}	

int main(void) {
	N = in();
	K = in();

	int i;

	for (i = 0; i < N; i++) {
		x[i] = in();
	}

	int id = -1;
	int cnt = 0;
	int ans = INT_MAX / 3;

	for (i = 0; i < N && cnt <= K; i++) {
		int curr = func(i);

		if (curr < ans) {
			ans = curr;
			id = i + 1;
		}
		cnt += 1;
	}

	printf("%d\n", id);

    return 0;
}