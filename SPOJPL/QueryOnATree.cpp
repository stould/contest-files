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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 10005;
const int INF = INT_MAX / 3;

int T, N;
char TYPE[20];

int main(void){
    scanf("%d", &T);

    while(t--) {
        scanf("%d", &N);

        for(int i = 0; i < n - 1; i++){

        }

        while (1) {
            scanf("%s", TYPE);

            if (TYPE[0] == 'D') {
                break;
            }
            
            int a, b;

            scanf("%d%d", &a, &b);

            if (TYPE[0] == 'Q') {

            } else if(TYPE[0] == 'C') {

            }
        }
    }
    return 0;
}
