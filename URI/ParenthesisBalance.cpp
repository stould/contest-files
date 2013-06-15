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

int i, n;
char str[10010];

int main(void) {
    while(~scanf("%s", str)) {
        n = strlen(str);
        stack<char> s;
        REP(i, n) {
            if(str[i] == '(') {
                s.push('(');
            } else if(str[i] == ')') {
                if(!s.empty() && s.top() == '(') {
                    s.pop();
                } else {
                    s.push(')');
                }
            }
        }
        if(s.empty()) {
            puts("correct");
        } else {
            puts("incorrect");
        }
    }
    return 0;
}


