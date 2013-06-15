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

using namespace std;

typedef long long ll;
typedef long double ld;

string in;
int dp[500] = {0};

int main(void) {
    cin >> in;
    REP(i, in.size()) {
        if(in[i] == '+') dp[i + 1] = dp[i] + 1;
        else dp[i + 1] = dp[i] - 1;
    }
    cout << (*max_element(dp, dp + in.size()+1) - *min_element(dp, dp + in.size()+1)) << "\n";

    return 0;
}



