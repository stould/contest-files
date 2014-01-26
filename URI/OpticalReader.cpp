#include <bits/stdc++.h>

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

int n, s[5], more, ls;
int main(void) {
	while(scanf("%d", &n) && n != 0) {
        for(int x = 0; x < n; x++) {
            scanf("%d%d%d%d%d", &s[0], &s[1], &s[2], &s[3], &s[4]);
            ls = 0;
            for(int i = 0; i < 5; i++) {
                if(s[i] <= 127) ls++;
            }
            if(ls == 1) {
                for(int i = 0; i < 5; i++) {
                    if(s[i] <= 127) {
                        char at = 'A' + i;
                        printf("%c\n", at);
                        break;
                    }
                }
            } else {
                puts("*");
            }
        }
    }
    return 0;
}
