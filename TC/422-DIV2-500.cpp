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

class PrimeSoccer {
public:
	double getProbability(int, int);
};

double dp[50][50][50];
double skA, skB;

bool isPrime(int x) {
	if (x <= 1) return false;
	if (x == 2 || x == 3) {
		return true;
	}
	if (x % 2 == 0) return false;
	for (int i = 3; i < x; i += 2) {
		if (x % i == 0) return false;
	}
	return true;
}

double func(int id, int ga, int gb) {
	if (id == 18) {
		if (isPrime(ga) || isPrime(gb)) {
			return 1.0;
		} else {
			return 0.0;
		}
	} else {
		double& ans = dp[id][ga][gb];
		
		if (ans < 0.0) {
			ans = 0.0;
			
			ans += (skA) * (1.0 - skB) * func(id + 1, ga + 1, gb);
			ans += (1.0 - skA) * (skB) * func(id + 1, ga, gb + 1);

			ans += (skA) * (skB) * func(id + 1, ga + 1, gb + 1);
			ans += (1.0 - skA) * (1.0 - skB) * func(id + 1, ga, gb);
		}
		
		return ans;
	}
}

double PrimeSoccer::getProbability(int skillOfTeamA, int skillOfTeamB) {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			for (int k = 0; k < 50; k++) {
				dp[i][j][k] = -1.0;
			}
		}
	}

	skA = skillOfTeamA / 100.0;
	skB = skillOfTeamB / 100.0;
	
//	cout << skA << " " << skB << endl;
	
	return func(0, 0, 0);	
}

//Powered by [KawigiEdit] 2.0!
