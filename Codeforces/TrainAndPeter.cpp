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

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

string flags, F, S;

pair<int, int> KMP(string S, string K) {
    int l = INT_MAX, r = INT_MIN;
    vector<int> T(K.size()+1, -1);

    for(int i = 1; i <= K.size(); i++) {
        int pos = T[i - 1];
        while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
        T[i] = pos + 1;
    }

    int sp = 0;
    int kp = 0;
    while(sp < S.size()) {
        while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
        kp++;
        sp++;
        if(kp == K.size()) {
            l = min(l, (int) (sp - K.size()));
            r = max(r, (int) (sp - K.size()));
        }
    }
    return make_pair(l, r);
}

int main(void) {
    cin >> flags >> F >> S;

    pair<int, int> pA = KMP(flags, F), pB = KMP(flags, S);
    reverse(flags.begin(), flags.end());
    pair<int, int> pC = KMP(flags, F), pD = KMP(flags, S);

    bool ok1 = pA.first < pB.second && pA.first + F.size() <= pB.second, ok2 = pC.first < pD.second && pC.first + F.size() <= pD.second;

    if(ok1 && ok2) {
        puts("both");
    } else if(ok1) {
        puts("forward");
    } else if(ok2) {
        puts("backward");
    } else {
        puts("fantasy");
    }
    return 0;
}
