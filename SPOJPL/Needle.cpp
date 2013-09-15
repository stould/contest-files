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
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

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

void build_failure_function(vector<int>& F, const string & pattern) {
    int m = pattern.size();
    F[0] = -1;
    for(int i = 0; i < m; i++) {
        F[i+1] = F[i] + 1;
        while(F[i + 1] > 0 && pattern[i] != pattern[F[i+1]-1]) {
            F[i+1] = F[F[i+1]-1] + 1;
        }
    }
}

vector<int> KMP(const string & text, const string &pattern) {
    int j = 0, m = pattern.size(), n = text.size();
    vector<int> F(m + 1, 0);
    build_failure_function(F, pattern);
    vector<int> ans;
    for(int i = 0; i < n; i++) while(true) {
        if ( text[i] == pattern[j] ) {
            if (++j == m ) {
                ans.push_back(i - m + 1);
                j = F[j];
            }
            break;
        }
        if(j == 0) break;
        j = F[j];
    }
    return ans;
}

int i, n;
string needle, haysack;

int main(void) {
    ios::sync_with_stdio(false);
    while(cin >> n) {
        cin.ignore();
        getline(cin, needle);
        getline(cin, haysack);
        vector<int> s = KMP(haysack, needle);
        REP(i, s.size()) {
            cout << s[i] << "\n";
        }
        cout << "\n";
    }
    return 0;
}
