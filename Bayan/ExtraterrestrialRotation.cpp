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

int T, M, cnt;
string S[10];
char axis;
// f=0 t=1 b=2 e=3 d=4 r=5

//           tf rt br fb
int xA[4] = {1, 5, 2, 0};
int xB[4] = {0, 1, 5, 2};

//           dt bd eb te
int yA[4] = {4, 2, 3, 1};
int yB[4] = {1, 4, 2, 3};

//           df rd er fe
int zA[4] = {4, 5, 3, 0};
int zB[4] = {0, 4, 5, 3};

void rotate(int rot, char kind) {
	string buff[10];

	for (int i = 0; i < rot; i++) {
		for (int j = 0; j < 6; j++) {
			buff[j] = S[j];
		}
		
		for (int j = 0; j < 4; j++) {
			int nx = 0;

			if (kind == 'X') {
				S[xA[j]] = buff[xB[j]];
			} else if (kind == 'Y') {
				S[yA[j]] = buff[yB[j]];
			} else {
				S[zA[j]] = buff[zB[j]];
			}
		}		
	}
}

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		for (int i = 0; i < 6; i++) {
			cin >> S[i];
		}

		cin >> M;
		
		for ( ; M--; ) {
			cin >> axis >> cnt;
			rotate(cnt % 4, axis);
		}

		for (int i = 0; i < 6; i++) {
			cout << S[i] << " ";
		}
		cout << endl;
	}
    return 0;
}
