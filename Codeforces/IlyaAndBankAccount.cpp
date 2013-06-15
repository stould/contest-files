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
#include <numeric>
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

int N;

string inttostr(int x) {
    string ans = "";

    if (x == 0) return "0";
    while (x > 0) {
        ans += (char) (x % 10) + '0'; x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int stringtoint(string s) {
    istringstream ss(s);
    int ans; ss >> ans;
    return ans;
}

int main(void) {
    scanf("%d", &N);

    int ans = N;

    if (N == 0) {
        printf("0\n");
    } else if (N < 0) {
        string num = inttostr(-N);
        ans = max(ans, - stringtoint(num.substr(0, num.size() - 1)));
        if (num.size() >= 2) {
            ans = max(ans, - stringtoint(num.substr(0, num.size() - 2) + string(1, num[num.size()-1])));
        }
        printf("%d\n", ans);
    } else {
        printf("%d\n", N);
    }
    return 0;
}
