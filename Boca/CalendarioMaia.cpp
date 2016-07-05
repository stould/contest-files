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
typedef unsigned uint;

int meses[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int ddv[5] = {144000, 7200, 360, 20, 1};
int dp[8000][13][34];

bool isLeap(int Y) {
	if (Y < 0) Y = -Y;
	if ( ( (!(Y % 4)) && (Y % 100) ) || (!(Y % 400)) ) return true;
	return false;
}
int main(void) {
	int d, m, y;

	int past = 0;
	for(int i = -3113; i <= 4000; i++){
        for(int j = 1; j <= 12; j++) {
            for(int k = 1; k <= meses[j] + (isLeap(i) && j == 2); k++){
                dp[i + 3113][j][k] = past++;
            }
        }
    }
	
	while (scanf("%d/%d/%d", &d, &m, &y) == 3) {
		//cout << d << " " << m << " " << y << "\n";
		int days = dp[y + 3113][m][d] - dp[0][8][11];

		//cout << days << "\n";

		vector<int> ans(5);

		for (int i = 0; i < 5; i++) {
			ans[i] = days / ddv[i];
			days %= ddv[i];

			cout << ans[i];
			if (i != 4) {
				cout << ".";
			}
		}
		cout << "\n";
	}
	return 0;
}
