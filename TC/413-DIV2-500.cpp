#include <bits/stdc++.h>

using namespace std;

class ArithmeticProgression {
public:
	double minCommonDifference(int, vector <int>);
};

const double INF = 10000000101010.0;

double ArithmeticProgression::minCommonDifference(int a0, vector <int> seq) {
	int N = (int) seq.size();
	double L, M, H;	
	double ans = INF;
	
	L = 0.0;
	H = 10000000.0;		
	
	
	for (int x = 0; x < 70; x++) {
		M = (L + H) / 2.0;
	
		bool great = false;
		bool lesser = false;		
		
		for (int i = 0; i < N; i++) {
			int v = floor(a0 + (i + 1) * M);
			
			if (v > seq[i]) {
				great = true;
			} else if (v < seq[i]) {
				lesser = true;
			}			
		}			
				
		if (lesser) {
			L = M;
		} else {		
			H = M;
			if (!great) {
				ans = min(ans, M);
			}
		}
	}
	
	if (ans >= INF) ans = -1.0;
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!
