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

string inttostr(int x) {
    string ans = "";

    if (x == 0) return "0";
    while (x > 0) {
        ans += (char) (x % 10) + '0'; x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

const int MAXN = 100007;
int N, M, a[MAXN], b[MAXN];
string buff;
string a_str;
map<string, int> idx;

void build(void) {
    idx["C"] = idx["B#"] = 0;
    idx["Db"] = idx["C#"] = 1;
    idx["D"] = 2;
    idx["Eb"] = idx["D#"] = 3;
    idx["E"] = idx["Fb"] = 4;
    idx["F"] = idx["E#"] = 5;
    idx["Gb"] = idx["F#"] = 6;
    idx["G"] = 7;
    idx["Ab"] = idx["G#"] = 8;
    idx["A"] = 9;
    idx["Bb"] = idx["A#"] = 10;
    idx["Cb"] = idx["B"] = 11;
}

int KMP(string S, string K) {
    vector<int> T(K.size() + 1, -1);
    int matches = 0;

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
    int i, level;
    ios_base::sync_with_stdio(false);
    build();
    while (cin >> N >> M && N + M != 0) {
        a_str = "";
        for (i = 0; i < N; i++) {
            cin >> buff;
            a[i] = idx[buff];
            a_str += inttostr(a[i]);
        }


        for (i = 0; i < M; i++) {
            cin >> buff;
            b[i] = idx[buff];
        }

        bool ok = false;


        for (level = 0; level <= 11; level++) {
            string next = "";
            for (i = 0; i < M; i++) {
                next += inttostr((b[i] + level) % 12);
            }
            if (KMP(a_str, next)) {
                ok = true; break;
            }
        }

        printf("%s\n", ok ? "S" : "N");
    }
    return 0;
}
