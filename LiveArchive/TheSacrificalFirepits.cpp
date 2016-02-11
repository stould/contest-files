#include <bits/stdc++.h>

using namespace std;


int main() {
	int t;
	double s1, s2;

	cin >>t;

	while(t--) {
		cin >> s1 >> s2;    
		double ans;
		if(s1 == s2) {
			ans = ( s1 + s2 / 2 ) * s1 * sqrt(3) / 2;
		}
		else {
			double ma = max(s1, s2), me = min(s1, s2);
			if(me >= ma/2) {
				ans = (me + ma/2) * ma * sqrt(3) / 2;
			}
			else {
				ans = (ma * sqrt(3) / 2) * ma;
			}
		}
		printf("%.3lf\n", ans);
	}

	return 0;
}
