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
        ans.num = num - f.num;
        ans.denom = denom - f.denom;
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
    bool operator!=(const fraction& f) {
        return num != f.num || denom != f.denom;
    }
    bool operator==(const fraction& f) {
        return num == f.num && denom == f.denom;
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

int main(void) {

    return 0;
}

