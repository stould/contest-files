#include <cstdio>
#include <cstring>

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

int M, cnt[400];
char S[1000005];
int main(void) {
	for ( ; scanf("%d", &M) == 1 && M != 0; ) {
		scanf(" %[^\n]s", S);

		int N = strlen(S);
		int l = 0, ans = 0, sum = 0;

		memset(cnt, 0, sizeof(cnt));

		for (int i = 0; i < N; i++) {
			cnt[S[i]] += 1;

			if (cnt[S[i]] == 1) sum += 1;

			while (sum > M) {
				cnt[S[l]] -= 1;
				if (cnt[S[l]] == 0) {
					sum -= 1;
				}
				l++;
			}
			chmax(ans, i - l + 1);
		}

		printf("%d\n", ans);
	}
    return 0;
}
