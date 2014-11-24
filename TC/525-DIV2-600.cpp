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

using namespace std;

typedef long long Int;
typedef unsigned uint;

class DropCoins {
public:
	int getMinimum(vector <string>, int);
};

const int INF = 100010100;


int DropCoins::getMinimum(vector <string> board, int K) {				
	int N = (int) board.size();
	int M = (int) board[0].size();
	
	int x, y;
	
	int ans = INF;

	for (int i = 0; i < N; i++) {
		for (int k = i + 1; k <= N; k++) {
			for (int j = 0; j < M; j++) {
				for (int l = j + 1; l <= M; l++) {
					int cnt = 0;
					
					for (x = i; x < k; x++) {
						for (y = j; y < l; y++) {
							if (board[x][y] == 'o') {
								cnt += 1;
							}
						}
					}
					
					if (cnt == K) {
						int a = i;
						int b = (N - k);
						int c = j;
						int d = (M - l);
						
						ans = min(ans, a + b + c + d + min(a, b) + min(c, d));
					}				
				}
			}
		}
	}
	
	return ans == INF ? -1 : ans;
}

//Powered by [KawigiEdit] 2.0!
