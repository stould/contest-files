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

int value[30];
char S[MAXN];
Int sum[MAXN];
map<pair<int, Int>, int> seen;

int main(void) {
	for (int i = 0; i < 26; i++) {
		scanf("%d", &value[i]);
	}

	scanf("%s", S);
	
	int N = (int) strlen(S);

	Int ans = 0LL;
	
	for (int i = 1; i <= N; i++) {
		int curr = S[i - 1] - 'a';
		
		sum[i] += value[curr];
		sum[i] += sum[i - 1];

		ans += seen[make_pair(curr, sum[i - 1])];

		pair<int, Int> sc = make_pair(curr, sum[i]);		
		seen[sc] += 1;
	}

	printf("%lld\n", ans);
	
    return 0;
}
