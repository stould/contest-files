/* aajjbb */

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

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

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

struct GUMIAndSongsDiv2 {
	void fix(vector <int>& duration, vector <int>& tone) {
		int i, N = (int) duration.size();
		
		pair<int, int> vp[N];
		
		for (i = 0; i < N; i++) {
			vp[i] = make_pair(tone[i], duration[i]);
		}
		
		sort(vp, vp + N);
		
		for (i = 0; i < N; i++) {
			tone[i] = vp[i].first;
			duration[i] = vp[i].second;
		}
	}
	int maxSongs(vector <int> duration, vector <int> tone, int T) {
		int i, j, N = (int) duration.size(), ans = 0;
		
		fix(duration, tone);
		
		for (i = 0; i < (1 << N); i++) {
			int index = -1;
			int spent = 0;
			
			for (j = 0; j < N; j++) {
				if ((i >> j) & 1) {
					spent += duration[j];
					
					if (index != -1) {
						spent += tone[j] - tone[index];						
					}
					index = j;
				}
			}		
			if (spent <= T) chmax(ans, __builtin_popcount(i));
		}
		
		return ans;
	}
};

// Powered by FileEdit
