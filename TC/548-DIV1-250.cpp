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

class KingdomAndTrees {
public:
    int minLevel(vector <int>);
};

int KingdomAndTrees::minLevel(vector <int> heights) {
    int N = (int) heights.size();
    Int ans = -1;
	
    Int l = 0, h = 1000000000LL;
	
    while (l <= h) {
        int m = (int) ((l + h) / 2);
		
        vector<int> other = heights;
        bool fine = true;
		
        other[0] = max(1, other[0] - m);		
		
        for (int i = 1; i < N; i++) {
            if (other[i] > other[i - 1]) {
                other[i] = max(other[i - 1] + 1, other[i] - m);
            } else {
                other[i] = min(other[i - 1] + 1, other[i] + m);
				
            }
			
            if (other[i - 1] >= other[i]) {
                fine = false;
            }
        }
        if (fine) {
            ans = m;
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
	
    return (int) ans;
}

//Powered by [KawigiEdit] 2.0!

