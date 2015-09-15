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

class TravelOnMars {
public:
	int minTimes(vector <int>, int, int);
};

const int MAXN = 60;

int dst[MAXN][MAXN];

int TravelOnMars::minTimes(vector <int> range, int startCity, int endCity) {
	int N = (int) range.size();
	
	memset(dst, 63, sizeof(dst));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= range[i]; j++) {
			int l = (i - j + N) % N;
			int r = (i + j) % N;
			
			dst[i][l] = dst[i][r] = 1;
		}
	}	
	
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
			}
		}
	}
	
	return dst[startCity][endCity];
}

//Powered by [KawigiEdit] 2.0!
