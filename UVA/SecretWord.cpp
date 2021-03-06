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

int T, N;
string A, B, ans;

int KMP(string S, string K) {
    vector<int> T(K.size() + 1, -1);
    int matches = 0;

    if(K.size() == 0) {
        return matches;
    }
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
        if(kp == K.size()) matches += 1;
    }
    return matches;
}

int main(void) {
    int i;
    cin >> T;

    for ( ; T--; ) {
        cin >> A; N =(int) A.size(); B = A;
        reverse(B.begin(), B.end());

        int low = 1, high = N, mid;

        ans = "z";

        while (low <= high) {
            mid = (low + high) / 2;

            bool ok = false;

            string now = A.substr(0, mid);
            if (KMP(B, now) > 0 && A.substr(0, mid) == now) {
                ans = now;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}
