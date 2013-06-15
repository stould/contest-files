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

typedef unsigned long long hash;

int N;
string str, ans;

map<string, int> mp;

int main(void) {
    while(scanf("%d", &N) == 1) {
        mp.clear();
        cin >> str;
        int check = 0;
        for(int i = 0; i + N <= str.size(); i++) {
            string now = str.substr(i, N);
            mp[now] += 1;
            int value = mp[now];

            if(value > check) {
                check = value;
                ans = now;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
