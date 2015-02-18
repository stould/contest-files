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

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;


struct NextNumber {
	int getNextNumber(int N) {
		vector<int> bin(32, 0);
		
		REP(i, 32) if(N & 1 << i) bin[31-i] = 1;
		
		next_permutation(bin.begin(), bin.end());
		
		int ans = 0;
		
		REP(i, 32) if(bin[i] == 1) {
			ans += (int) (1 << (31 - i));
		}
		
		return ans;
	}
};


// Powered by FileEdit
