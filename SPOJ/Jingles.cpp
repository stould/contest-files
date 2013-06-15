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

#define MAXN 220

char str[MAXN];
int i, j, n, ans;

struct fraction {
    int num, denom;
    fraction(int num, int denom): num(num), denom(denom){
    }
    fraction() { num = 0; denom = 0; }
    void reduce(fraction& f) {
        int l = gcd(f.num, f.denom);
        f.num = f.num/l;
        f.denom = f.denom/l;
    }
    fraction operator+(const fraction& f) {
        fraction ans;
        int l = lcm(denom, f.denom);
        ans.num = ((l / denom) * num) + ((l / f.denom) * f.num);
        ans.denom = l;
        reduce(ans);
        return ans;
    }

    fraction operator-(const fraction& f) {
        fraction ans;
        int l = lcm(denom, f.denom);
        ans.num = ((l / denom) * num) - ((l / f.denom) * f.num);
        ans.denom = l;
        reduce(ans);
        return ans;
    }
    fraction operator*(const fraction& f) {
        fraction ans;
        ans.num = num * f.num;
        ans.denom = denom * f.denom;
        reduce(ans);
        return ans;
    }
    fraction operator/(const fraction& f) {
        fraction ans;
        ans.num = num * f.denom;
        ans.denom = denom * f.num;
        reduce(ans);
        return ans;
    }
    bool operator!=(const fraction& f) const {
        return num != f.num || denom != f.denom;
    }
    bool operator==(const fraction& f) const {
        return num == f.num && denom == f.denom;
    }
    bool operator<(const fraction& f) const {
        return num*denom < f.num*f.denom;
    }
    bool operator>(const fraction& f) const {
        return num*denom > f.num*f.denom;
    }
    friend ostream &operator<<(ostream &out, fraction f) {
        out << f.num << "/" << f.denom << "\n";
        return out;
    }
    friend istream &operator>>(istream &in, fraction f) {
        in >> f.num >> f.denom;
        return in;
    }
};

map<char, fraction> mp;

int main(void) {
    mp['W'] = fraction(1, 1);
    mp['H'] = fraction(1, 2);
    mp['Q'] = fraction(1, 4);
    mp['E'] = fraction(1, 8);
    mp['S'] = fraction(1, 16);
    mp['T'] = fraction(1, 32);
    mp['X'] = fraction(1, 64);
    while(scanf("%s", str) == 1) {
        if(!strcmp(str, "*")) break;
        n = strlen(str);
        ans = 0;
        REP(i, n) {
            if(str[i] != '/') {
                int j = i + 1;
                fraction tmp = mp[str[i]];
                while(j < n && str[j] != '/') {
                    tmp = tmp + mp[str[j]];
                    j += 1;
                }
                i = j;
                if(tmp == fraction(1, 1)) ans += 1;

            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

