#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

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

int main(void) {
	N = in();

	int i, j;
	int id = 0;	
	bool sent = true;

	vector<int> vp[N];

	for (i = 0; i < N * N; i++) {
		vp[id].push_back(i + 1);

		if (sent) {
			id += 1;
			if (id == N) {
				id -= 1;
				sent = false;
			}
		} else {
			id -= 1;
			if (id == -1) {
				id += 1;
				sent = true;
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < (int) vp[i].size(); j++) {
			printf("%d ", vp[i][j]);
		}
		printf("\n");
	}
    return 0;
}