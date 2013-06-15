#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <utility>
#include <valarray>
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

const int MAXN = 100010;
int N, L, now, num, minimo;

int main(void) {
    ios::sync_with_stdio(false);

    while(cin >> N >> L && (N+L != 0)) {
        deque<int> mario;
        minimo = 1;

        FOR(i, 0, L) {
            cin >> now;
            if(i == 0) {
                mario.push_back(now);
            }
            while(!mario.empty() && (now - mario.front() >= N)) {
                mario.pop_front();
            }
            if(i != 0) {
                mario.push_back(now);
            }

            if(mario.size() > minimo) {
                minimo = (int) mario.size();
            }
        }
        cout << N - minimo << endl;
    }
    return 0;
}
