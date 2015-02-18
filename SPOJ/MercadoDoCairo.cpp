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

const int MAXN = 1010;

int N, T;
int tree[MAXN][MAXN];

int get_max(int x, int y) {
    int result = 0;
	
    for (int i = x; i >= 0; i = (i & (i +1)) - 1) {
        for (int j = y; j >= 0; j = (j & (j +1)) - 1) {
            chmax(result, tree[i][j]);
        }
    }
	
    return result;
}


void update(int x, int y, int new_value) {
    for (int i = x; i >= 0; i = (i & (i +1)) - 1) {
        for (int j = y; j >= 0; j = (j & (j +1)) - 1) {
            tree[i][j] += new_value;
        }
    }
}


int main(void) {
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		cin >> N;

		memset(tree, 0, sizeof(tree));
		
		int X, Y;
		
		for (int i = 0; i < N; i++) {
			cin >> X >> Y;
			
			update(X, Y, get_max(X, Y) + 1);
			cout << get_max(X, Y) << endl;
		}
		cout << "\n";
		//cout << get_max(1000, 1000) << endl;
	}
	
    return 0;
}
