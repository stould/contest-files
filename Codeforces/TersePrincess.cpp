#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

const double EPS = 1e-9;

int N, A, B, V[110];

int main(void) {
    scanf("%d%d%d", &N, &A, &B);

	int i = 1;
	int sum = 2;

    V[0] = 2;

	if (B == 0) {		
		V[1] = 2;
		sum += V[1];
		i++;		
	}
	
	for ( ; i < N; i++) {
		if (B > 0) {
			V[i] = sum + 1;
			B -= 1;
			sum += V[i];
		} else {
			if (A > 0) {
				V[i] = V[i - 1] + 2;			
				A -= 1;
			} else {
				V[i] = 1;
			}
		}
	}
	if (A > 0 || B > 0) {
		cout << "-1\n";
	} else {
		for (i = 0; i < N; i++) {
			cout << V[i] << " ";
		}
		cout << "\n";
	}
    return 0;
}
