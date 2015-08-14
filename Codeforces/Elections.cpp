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
typedef unsigned uint;

int N, M;
Int P[110][110];

int main(void) {
	cin >> N >> M;

	vector<int> win(110, 0);
	
	for (int i = 0; i < M; i++) {
		int curr = 0, id = -1;
		
		for (int j = 0; j < N; j++) {
			cin >> P[i][j];

			if (P[i][j] > curr) {
				curr = P[i][j];
				id = j;
			}	
		}

		win[id] += 1;
	}

	int curr = 0, winner = -1;
	
	for (int i = 0; i < N; i++) {
		if (win[i] > curr) {
			curr = win[i];
			winner = i + 1;
		}
	}

	cout << winner << "\n";
	
	return 0;
}
