#line 98 "LotteryTicket.cpp"
/*
 aajjbb
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

int N, check = 0;
int coins[4];

void rec(int x, int sum, int ans) {
	if(sum == ans) check = true;
	if(x >= N) return;
	sum += coins[x];
	rec(x + 1, sum, ans);
	rec(x + 1, sum - coins[x], ans);
}

struct LotteryTicket {
	string buy(int price, int b1, int b2, int b3, int b4) {
		N = 4;
		coins[0] = b1; coins[1] = b2; coins[2] = b3; coins[3] = b4;		
		rec(0, 0, price);
		return check ? "POSSIBLE" : "IMPOSSIBLE";		
	}
};


// Powered by FileEdit
