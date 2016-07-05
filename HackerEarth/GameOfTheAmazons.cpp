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

const int N = 10;

int field[N][N], player;

int dox[4] = {0, 0, -1, 1};
int doy[4] = {-1, 1, 0, 0};	

struct move {
	int init_i, init_j;
	int move_i, move_j;
	int arrw_i, arrw_j;

	move() {}

	move(int init_i, int init_j, int move_i, int move_j, int arrw_i, int arrw_j):
		init_i(init_i),
		init_j(init_j),
		move_i(move_i),
		move_j(move_j),
		arrw_i(arrw_i),
		arrw_j(arrw_j){}		
};

bool inside(int i, int j) {
	return i >= 0 && j >= 0 && i < N && j < N;
}

int countLiberties(int i, int j) {
	int ans = 0;
	
	for (int k = 0; k < 4; k++) {
		int ni = i + dox[k];
		int nj = j + doy[k];
		
		if (inside(ni, nj) && field[ni][nj] == 0) {
			ans += 1;
		}
	}	
	
	return ans;
}

int getLiberties(int p) {
	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (field[i][j] == p) {
				ans += countLiberties(i, j);
			}
		}
	}
	
	return ans;	
}

int search() {

}

int main(void) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> field[i][j];
		}
	}

	cin >> player;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (field[i][j] == player) {
				
			}
		}
	}
	
	return 0;
}
