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

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

string vowel = "aiyeou";
string uvowel = "AIYEOU";
string consonant = "bkxznhdcwgpvjqtsrlmf";
string uconsonant = "BKXZNHDCWGPVJQTSRLMF";

string buff;

int main(void) {
    int i;

    for ( ; getline(cin, buff); ) {
        string ans;

        for (i = 0; i < (int) buff.size(); i++) {
            if (!((buff[i] >= 'a' && buff[i] <= 'z') || (buff[i] >= 'A' && buff[i] <= 'Z'))) ans += buff[i];
            else {
                int fv = vowel.find(buff[i]);
                int fc = consonant.find(buff[i]);

                int fv1 = uvowel.find(buff[i]);
                int fc1 = uconsonant.find(buff[i]);

                if (fv != string::npos) {
                    ans += vowel[(fv + 3) % (int) vowel.size()];
                } else if (fc != string::npos) {
                    ans += consonant[(fc + 10) % (int) consonant.size()];
                } else if (fv1 != string::npos) {
                    ans += uvowel[(fv1 + 3) % (int) uvowel.size()];
                } else {
                    ans += uconsonant[(fc1 + 10) % (int) uconsonant.size()];
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
