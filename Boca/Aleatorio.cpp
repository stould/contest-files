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

template<typename T> void chmin(T& a, T b) {
    a = (a > b) ? b : a;
}
template<typename T> void chmax(T& a, T b) {
    a = (a < b) ? b : a;
}
int in() {
    int x;
    scanf("%d", &x);
    return x;
}

using namespace std;

typedef long long Int;
typedef unsigned uint;

string N;

int strint(string str) {
    return atoi(str.c_str());
}

string intstr(int s) {
    string ans;

    while (s > 0) {
        int digit = s % 10;

        ans += (digit + '0');

        s /= 10;
    }

    reverse (ans.begin(), ans.end());

    return ans;
}

int main(void) {
    for ( ; cin >> N && N != "0"; ) {
        set<string> s;
        s.insert(N);

        while (1) {
            string str = intstr(strint(N) * strint(N));

            while (str.size() < 8) str = "0" + str;

            string buff = str.substr(2, 4);

            if (s.count(buff)) break;
            s.insert(buff);
            N = buff;
        }

        printf("%d\n", (int) s.size());
    }
    return 0;
}
