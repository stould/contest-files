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

const int MAXN = 610;

int N;
string S;
bool vis[MAXN][MAXN][MAXN];

int main(void) {
	cin >> N >> S;

	int R = 0;
	int G = 0;
	int B = 0;
	
	for (int i = 0; i < N; i++) {		
		if (S[i] == 'R') {
			R += 1;
		} else if (S[i] == 'G') {
			G += 1;
		} else {
			B += 1;
		}
	}
	
	queue<pair<int, pair<int, int> > > q;
	q.push(make_pair(R, make_pair(G, B)));
	vis[R][G][B] = true;

	bool canR = false;
	bool canG = false;
	bool canB = false;

	while (!q.empty()) {
		int r = q.front().first;
		int g = q.front().second.first;
		int b = q.front().second.second;

		q.pop();

		if (r > 0 && (g == 0 && b == 0)) {
			canR = true;
			continue;
		}
		if (g > 0 && (r == 0 && b == 0)) {
			canG = true;
			continue;
		}
		if (b > 0 && (r == 0 && g == 0)) {
			canB = true;
			continue;
		}

		if (r > 0 && b > 0 && !vis[r - 1][g + 1][b - 1]) {
			q.push(make_pair(r - 1, make_pair(g + 1, b - 1)));
			vis[r - 1][g + 1][b - 1] = true;
		}
		if (r > 0 && g > 0 && !vis[r - 1][g - 1][b + 1]) {
			q.push(make_pair(r - 1, make_pair(g - 1, b + 1)));
			vis[r - 1][g - 1][b + 1] = true;
		}
		if (g > 0 && b > 0 && !vis[r + 1][g - 1][b - 1]) {
			q.push(make_pair(r + 1, make_pair(g - 1, b - 1)));
			vis[r + 1][g - 1][b - 1] = true;
		}
		if (r > 1 && !vis[r - 1][g][b]) {
			q.push(make_pair(r - 1, make_pair(g, b)));
			vis[r - 1][g][b] = true;
		}
		if (g > 1 && !vis[r][g - 1][b]) {
			q.push(make_pair(r, make_pair(g - 1, b)));
			vis[r][g - 1][b] = true;		
		}
		if (b > 1 && !vis[r][g][b - 1]) {
			q.push(make_pair(r, make_pair(g, b - 1)));
			vis[r][g][b - 1] = true;
		}
	}
	
	string ans = "";
	
	if (canB) {
		ans += "B";
	}
	if (canG) {
		ans += "G";
	}
	if (canR) {
		ans += "R";
	}

	cout << ans << "\n";

	return 0;
}
