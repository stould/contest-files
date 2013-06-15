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
typedef unsigned long long hash;

const int MAXN = 40010;
int N, M; //[0] times, [0], occur
hash h[100010][2];
hash powers[MAXN];
char str[MAXN];

const int BASE = 3;

hash get_hash(char *s, int len) {
    int ans = 0;
    for(int i = 0; i < len; i++) {
        ans += (((s[i]-'a'+1))*powers[i]);
    }
    return ans;
}

int update_hash(char *s, int &current, int take, int put, int len) {
    current -= (((s[take]-'a'+1)*powers[take]));
    current += (((s[put]-'a'+1)*powers[take]));
    current = abs(current);
}

int main(void) {
    freopen("i.in", "r", stdin);
    powers[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        powers[i] = powers[i-1]*BASE;
    }
    for( ; scanf("%d", &M) && M != 0; ) {
        scanf("%s", str); N = strlen(str);

        int low = 0, high = N+1, mid;

        int max_occur = 0, last = 0, len = 0;

        while(low <= high) {
            mid = (low + high) / 2;
            memset(h, 0, sizeof(h));

            int hash = get_hash(str, mid), now = 0, actual_last = 0;
            for(int i = 0; i + mid <= N; i++) {
                if(i > 0) update_hash(str, hash, i-1, mid+i-1, mid);
                h[hash][0] += 1;
                h[hash][1] = i;
                if(h[hash][0] > now) {
                    now = h[hash][0];
                    actual_last = h[hash][1];
                }
                printf("%d - %d ->", i, i + mid);
                for(int j = i; j - i < mid; j++) {
                    printf("%c", str[j]);
                }
                printf(" - %d\n", hash);
            }
            printf("\n");
            printf("%d %d\n", M, now);
            if(now >= M ) {
                max_occur = now;
                last = actual_last;
                low = mid + 1;
                len = mid;
            } else {
                high = mid - 1;
            }
        }
        if(max_occur == 0) {
            puts("none");
        } else {
            printf("%d %d\n", len, last);
        }
    }
    return 0;
}
