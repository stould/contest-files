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
 
class TaroFillingAStringDiv1 {
public:
	int getNumber(int, vector <int>, string);
};
 
const Int MOD = 1000000007LL;
 
int TaroFillingAStringDiv1::getNumber(int N, vector <int> position, string value) {
  
	int M = (int) value.size();
  
	vector<pair<int, char> > vs;
  
	for (int i = 0; i < M; i++) {
		vs.push_back(make_pair(position[i], value[i]));
	}
  
	sort(vs.begin(), vs.end());
  
	if (N == M) {
		return 1;
	} else {
		Int ans = 1LL;
    
		for (int i = 0; i < M - 1; i++) {
			if (vs[i].first != vs[i + 1].first - 1) {
				int df = vs[i + 1].first - vs[i].first;      
        
				if (vs[i].second == vs[i + 1].second) {
					if (df % 2 != 0) {
						ans = ans * ((Int) df);
					} 
				} else {
					if (df % 2 == 0) {
						ans = ans * ((Int) df);
					}
				}
        
				ans = ans % MOD;
			}
		}
		return (int) (((ans % MOD) + MOD) % MOD);  
	}    
}
