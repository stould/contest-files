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

class CutTheNumbers {
public:
	int maximumSum(vector <string>);
};

int N, M, best = 0;
vector<string> masks;
vector<string> board;

string toInt(int x) {
	string ans = "";
	
	while (x > 0) {
		ans = ans + char('0' + (x % 2));
		x /= 2;
	}
	
	while (ans.size() < M) {
		ans = ans + "0";
	}
	
	reverse(ans.begin(), ans.end());
	
	return ans;
}

void bt(vector<string> mask, int depth) {
	if (depth == N) {
		bool seen[N][M];
		
		memset(seen, false, sizeof(seen));
		
		int curr = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!seen[i][j]) {
					int p = 0;
					
					if (mask[i][j] == '1') {
						for (int k = j; k < M; k++) {
							if (mask[i][k] == '0') {
								break;
							}
							p = p * 10 + (board[i][k] - '0');
							seen[i][k] = true;
						}
					} else {
						for (int k = i; k < N; k++) {
							if (mask[k][j] == '1') {
								break;
							}
							p = p * 10 + (board[k][j] - '0');
							seen[k][j] = true;
						}
					}
					curr += p;					  
				}
			}
		}
		
		best = max(best, curr);
	} else {
		for (int i = 0; i < (int) masks.size(); i++) {
			vector<string> next = mask;
			next.push_back(masks[i]);
			
			bt(next, depth + 1);
		}
	}
}

int CutTheNumbers::maximumSum(vector <string> board) {
	::board = board;

	N = (int) board.size();	
	M = (int) board[0].size();

	for (int i = 0; i < (1 << M); i++) {
		masks.push_back(toInt(i));		
	}

	bt(vector<string>(), 0);
	
	return best;	
}

//Powered by [KawigiEdit] 2.0!
