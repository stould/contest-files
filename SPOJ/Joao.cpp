#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define REP(i, n) for(i = 0; i < n; i++)

using namespace std;

typedef long long ll;

template<typename T> T max(T a, T b) { return a > b ? a : b; }
template<typename T> T min(T a, T b) { return a > b ? b : a; }
template<typename T> void chmax(T &a, T b) { a = b > a ? b : a; }
template<typename T> void chmin(T &a, T b) { a = b > a ? a : b; }

const double INF = 1e10;

int n;

string tos(ll a) {
    string ans = "";
    while(a > 0) {
        ans += ((a % 10) + '0');
        a /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int toi(string s) {
    int base = 0, ans = 0;

    for(int i = s.size() - 1; i >= 0; i--) {
        ans += (s[i] - '0') * pow(10, base);
        base++;
    }
    return ans;
}

bool is(int n) {
    if(n == 1) return true;
    string help = tos((ll)n*n);

    for(int i = 0; i < help.size(); i++) {
        int a = toi(help.substr(0, i));
        int b = toi(help.substr(i, help.size()));

        if(a > 0 && b > 0 && a + b == n) return true;
    }
    return false;
}

int main(void) {
    for( ; scanf("%d", &n) && n != 0; ) {
        if(is(n)) {
            printf("%d: %c\n", n, 'S');
        } else {
            printf("%d: %c\n", n, 'N');
        }
    }
    return 0;
}


