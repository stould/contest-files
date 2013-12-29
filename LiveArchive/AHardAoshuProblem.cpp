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

int T, N;
string A, B, C;
int v[10];
int ans;
map<char, int> mp;

Int f(string& s) {
    int i;
    int id = 0;
    Int ans = 0;

    for (i = (int) s.size() - 1; i >= 0; i--)  {
        if (s.size() > 1 && i == 0 && v[mp[s[i]]] == 0) return -1LL;
        ans += (Int) pow(10, id++) * v[mp[s[i]]];        
    }

    return ans;
}

void dfs(int pos, int mask) {
    if (pos == N) {
        Int sa = f(A);
        Int sb = f(B);
        Int sum = f(C);

        if (sa == -1LL || sb == -1LL || sum == -1LL) return;


        if (sa + sb == sum) {            
            ans += 1;
        }
        if (sa - sb == sum) {
            ans += 1;            
        }
        if (sa * sb == sum) {
            ans += 1;            
        }
        if (sb != 0 && sum * sb == sa) {
            ans += 1;                                        
        }
    } else {
        int i;
        for (i = 0; i < 10; i++) if (!(mask & (1 << i))) {
            v[pos] = i;
            dfs(pos + 1, mask | (1 << i));            
        }
    }
}

int main(void) {
    T = in();

    int i;

    for ( ; T--; ) {
        cin >> A >> B >> C;       

        set<char> s;

        for (i = 0; i < (int) A.size(); i++) s.insert(A[i]);
        for (i = 0; i < (int) B.size(); i++) s.insert(B[i]);
        for (i = 0; i < (int) C.size(); i++) s.insert(C[i]);

        int id = 0;
        for(set<char>::iterator it = s.begin(); it != s.end(); it++) {
            mp[*it] = id++;
        }

        N = (int) s.size();
        ans = 0;

        dfs(0, 0);
        
        printf("%d\n", ans);
    }

    return 0;
}