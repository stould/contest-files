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

const int MAXN = 100005;

int N;
int P[MAXN], C[MAXN];

int main(void) {
	cin >> N;

	vector<pair<int, int> > vp;

	for (int i = 0; i < N; i++) {
		cin >> P[i];		
	}

	for (int i = 0; i < N; i++) {
		int j = i + 1;
		while (j < N) {
			if (P[j] < P[j - 1]) {
				P[j] = (j - 2 >= 0 ? P[j - 2] + 1 : P[j] - 1);
				C[j] += 1;				
			}
			j++;
		}
		i = j;
	}
	for (int i = 0; i < N; i++) {
		cout << P[i] << " ";
	}
	cout << "\n";
	int best = 0;
	for (int i = 0; i < N;  i++) {
		int j = i;
		int cnt = 0;
		while (j < N && cnt < 2) {			
			cnt += C[i];
			if (j - 1 >= 0 && P[j] <= P[j - 1]) break;
			j++;
		}
		if (j == N) j--;
		chmax(best, j - i + 1);
		if (j == N) j++;
	}
	/*
		int j = i + 1;
		chmax(best, vp[i].second - vp[i].first + 1);
		//		cout << vp[i].first << " "<< vp[i].second << "\n";
		//		cout << "go\n";
		while (j < N && vp[j].first <= vp[i].second) {
			//	cout << vp[j].first << " "<< vp[j].second << "\n";

			if (vp[j].first == vp[i].second && vp[i].first - 1 >= 0 && vp[j].second + 1 < N && P[vp[i].first - 1] + 1 < P[vp[j].second + 1]) {
				chmax(best, vp[j].second - vp[i].first + 1);							
			}
			j++;
		}
	}
	*/
	cout << best << "\n";
    return 0;
}
