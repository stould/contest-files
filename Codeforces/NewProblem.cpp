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
set<string> s;
string ans = "abcdefghijklmnopqrstuvwxyzz";

void rec(string now) {
    if(!s.count(now) && now != "") {
        if(now.size() < ans.size() || now < ans) {
            ans = now;
        }
        return;
    }
    for(char c = 'a'; c <= 'z'; c++) rec(now + c);
}

int main(void) {
    scanf("%d", &N);

    REP(i, N) {
        string str; cin >> str;
        for(int j = 0; j < str.size(); j++) {
            for(int k = 1; k <= str.size() - j; k++) {
                s.insert(str.substr(j, k));
            }
        }
    }
    rec("");
    printf("%s\n", ans.c_str());
    return 0;
}
