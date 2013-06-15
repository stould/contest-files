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

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

typedef long long ll;
typedef long double ld;

int a, b, m, r0;

vector<ll> form;

ll seq(int i) {
    return (a * form[i - 1] + b) % m;
}

int main(void) {
    cin >> a >> b >> m >> r0;
    form.push_back(r0);

    int ans = 0;

    for(int i = 1; ; i++) {
        form.push_back(seq(i));
        int ct = 0;
        for(int j = i - 1; ; j--) {
            if(ct == 3)
        }

    }

    return 0;
}


