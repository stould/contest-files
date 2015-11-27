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

int T;
int ord[3];

pair<int, bool > roots(int a, int b, int c) {
	pair<int, bool> ans;
	
	int delta = b * b - 4 * a * c;

	int sq = (int) (sqrt(delta) + 0.5);

	if (sq * sq == delta) {
		ans.second = true;
		ans.first = ((-b) - (int) sqrt(delta)) / 2 * a;		
	} else {
		ans.second = false;
	}
	
	return ans;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	while (cin >> T && T != -1) {
		//for (T = 1; T <= 10000; T++) {
		set<pair<int, pair<int, int> > > ans;		
		
		for (int a = 1; a <= max(1, min(T / 4, 100)); a++) {
			for (int bc = 0; bc <= max(1, T / 2); bc++) {
				int bpc = (T - bc) / a;
				
				pair<int, bool> cc = roots(-1, bpc, -bc);

				if (cc.second) {
					int c = cc.first;
					int b = bpc - c;
					
					if (a * b + a * c + b * c == T) {						
						ord[0] = a;
						ord[1] = b;
						ord[2] = c;

						if (ord[0] > ord[1]) swap(ord[0], ord[1]);
						if (ord[0] > ord[2]) swap(ord[0], ord[2]);
						if (ord[1] > ord[2]) swap(ord[1], ord[2]);
						   
						//cout << a << " " << b << " " << c << "\n";
						
						//cout << ord[0] << " " << ord[1] << " " << ord[2] << "\n";
						//cout << a << " => " << ord[0] << " " << ord[1] << " " << ord[2] << "\n";
						ans.insert(make_pair(ord[0], make_pair(ord[1], ord[2])));
						//if (b >= min(c, a)) break;
					}
				}			
			}
		}
		cout << ans.size() << "\n";
	}
	return 0;
}
