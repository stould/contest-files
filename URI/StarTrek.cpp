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

const int MAXN = 1000006;

int N;
int P[MAXN];
bool vis[MAXN];

int main(void) {
	cin >> N;

	Int all = 0;

	for (int i = 0; i < N; i++) {
		cin >> P[i];

		all += P[i];
	}

	int id = 0;
	int seen = 0, sum = 0;
	
	while (1) {
		if (!vis[id]) seen += 1;
		vis[id] = true;
		
		int buff = P[id];
		int next = id;
		
		if (buff % 2 == 1) {
			next += 1;
		} else {
			next -= 1;
		}

		sum += 1;
		P[id] = max(0, P[id] - 1);

		if (next < 0 || next >= N || P[next] == 0) {
			break;
		}

		id = next;
	}

	cout << seen << " " << all - sum << "\n";
	
	return 0;	
}
