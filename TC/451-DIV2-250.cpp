#line 66 "ReverseMagicalSource.cpp"
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

struct ReverseMagicalSource {
	int find(int source, int A) {
		for(int i = A + 1; ; i++) {			
			if(check(i, source)) {
				return i;			
			}
		}
	}
	bool check(int s, int source) {
		long start = source;
		while(start <= s) {
			if(start == s) return true;
			source = (long) (source * pow((double)10, 1));
			start += source;
		}
		return false;
	}
};


// Powered by FileEdit
