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

int N, M;
string S[60];

bool find(char a, char b, char c, char d) {
	string as = string(1, a) + string(1, b) + string(1, c) + string(1, d);

	sort(as.begin(), as.end());

	return as == "acef";
}

int cv(int a, int b) {
	return b * N + a;
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	set<vector<int> > vs;
	
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++) {
			if (j - 1 >= 0) {
				vector<int> vp;
				if (find(S[i][j], S[i][j - 1], S[i + 1][j], S[i + 1][j - 1])) {
					vp.push_back(cv(i, j));
					vp.push_back(cv(i, j - 1));
					vp.push_back(cv(i + 1, j));
					vp.push_back(cv(i + 1, j - 1));
					sort(vp.begin(), vp.end());
					vs.insert(vp);
				}
			}
			if (j + 1 < M) {
				vector<int> vp;
				if (find(S[i][j], S[i][j + 1], S[i + 1][j], S[i + 1][j + 1])) {
					vp.push_back(cv(i, j));
					vp.push_back(cv(i, j + 1));
					vp.push_back(cv(i + 1, j));
					vp.push_back(cv(i + 1, j + 1));
					sort(vp.begin(), vp.end());
					vs.insert(vp);
				}
			}
		}
	}

	cout << vs.size() << "\n";
	
	return 0;	
}
