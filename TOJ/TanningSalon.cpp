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
#include <numeric>
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

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 30;
int N, buff[MAXN];
char str[MAXN];

int main(void) {
    int i;
    for ( ; scanf("%d%s", &N, str) == 2 && N != 0; ) {
        int curr = 0, ans = 0;
        memset(buff, 0, sizeof(buff));

        for (i = 0; i < strlen(str); i++) {
            int now = str[i] - 'A';
            buff[now] += 1;
            if (buff[now] == 2) {
                curr -= 1;
            } else {
                curr += 1;
                if (curr > N) ans += 1;
            }
        }
        if (ans == 0) {
            printf("All customers tanned successfully.\n");
        } else {
            printf("%d customer(s) walked away.\n", ans);
        }
    }
    return 0;
}
