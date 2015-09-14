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

const int MAXN = 3200005;                 
const int MAX_LEN = 3;

int T, N;
int P[100005];

int child[MAXN][2];
int n;
	
void resetTrie() {
	n = 1;
	memset(child, 0, sizeof(child));
}

void addWord(int x) {
	int now = 0;
	
	for (int i = 31; i >= 0; i--) {
		int letter_pos = (x & (1 << i)) != 0;
		
		if (!child[now][letter_pos]) {
			child[now][letter_pos] = n++;
		}		
		now = child[now][letter_pos];
	}
}

int query(int x) {
	int value = 0;
		
	int now = 0;

	for (int i = 31; i >= 0; i--) {
		int wish = (x & (1 << i)) != 0;

		wish ^= 1;
		
		if (child[now][wish]) {
			value += (1 << i);
			now = child[now][wish];
		} else if (child[now][wish ^ 1]) {
			now = child[now][wish ^ 1];
		}
	}

	return value;
}

int main(void) {
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		cin >> N;

		int ans = 0;
		int all = 0;

		addWord(0);
		
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);

			addWord(all);
			all ^= P[i];
			
			chmax(ans, query(P[i]));
		}

		resetTrie();
		printf("%d\n", ans);
	}
	
	return 0;
}
