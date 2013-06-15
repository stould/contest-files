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

char buff[19];

void func(void) {
    if (!strcmp(buff, "HELLO")) printf("ENGLISH\n");
    else if (!strcmp(buff, "HOLA")) printf("SPANISH\n");
    else if (!strcmp(buff, "HALLO")) printf("GERMAN\n");
    else if (!strcmp(buff, "BONJOUR")) printf("FRENCH\n");
    else if (!strcmp(buff, "CIAO")) printf("ITALIAN\n");
    else if (!strcmp(buff, "ZDRAVSTVUJTE")) printf("RUSSIAN\n");
    else printf("UNKNOWN\n");
}

int main(void) {
    while (scanf("%s", buff) == 1 && strcmp(buff, "#")) {
        func();
    }
    return 0;
}
