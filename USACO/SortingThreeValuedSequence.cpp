/*
  ID: jeferso1
  LANG: C++
  TASK: sort3
*/

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

int N;
int P[1010];
int cnt[5];

int currPos(int i) {
	i += 1;

	if (i <= cnt[1]) {
		return 1;
	} else {
		if (i <= cnt[1] + cnt[2]) {
			return 2;
		} else {
			return 3;
		}
	}
}

int main(void) {
	//freopen("sort3.in", "r", stdin);
	//freopen("sort3.out", "w", stdout);
	
	scanf("%d", &N);

	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
		cnt[P[i]] += 1;
	}
	
	for (int i = 0; i < N; i++) {
		if (P[i] == 1) {
			for (int j = 0; j < N; j++) {
				if (P[j] == 2) {
					cout << i << " " << j << " => " << currPos(i) << " " << currPos(j) << " " << P[i] << " " << P[j] << "\n";
					if (currPos(i) == 2 && currPos(j) == 1) {
						swap(P[i], P[j]);
						ans += 1;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (P[i] == 2) {
			for (int j = 0; j < N; j++) {
				if (P[j] == 3) {
					cout << i << " " << j << " => " << currPos(i) << " " << currPos(j) << " " << P[i] << " " << P[j] << "\n";
					if (currPos(i) == 3 && currPos(j) == 2) {
						swap(P[i], P[j]);
						ans += 1;
						break;
					}
				}
			}
		}
		}
	for (int i = 0; i < N; i++) {
		if (P[i] == 1) {
			for (int j = 0; j < N; j++) {
				if (P[j] == 3) {
					cout << i << " " << j << " => " << currPos(i) << " " << currPos(j) << " " << P[i] << " " << P[j] << "\n";
					if (currPos(i) == 3 && currPos(j) == 1) {
						swap(P[i], P[j]);
						ans += 1;
						break;
					}
				}
			}
		}
		}	
	for (int i = 0; i < N; i++) {
		printf("%d ", P[i]);
	}
	printf("\n");

	printf("%d\n", ans);
			 
	return 0;
}
