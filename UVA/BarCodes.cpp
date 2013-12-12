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

char buff[110];
map<string, char> cd;

char bag[110][110];

int N;

int mapp[110];

char S[600];
char ans[600];

char let[105];

int cnt;
void dfs(int pos, int depth) {
    if (cnt >= 100) {
        return;
    }
    if (S[pos] == '\0') {
        ans[depth] = '\0';
        puts(ans);
        cnt += 1;
        return;
    } else {
        int i;

        for (i = 0; i < N; i++) {
            int j;
            int k = pos;
            int mm = mapp[i];

            while (S[k] == '0') k += 1;

            for (j = 0; bag[mm][j]; j++, k++) {
                if (S[k] != bag[mm][j]) break;
            }

            if (bag[mm][j] == '\0') {
                ans[depth] = let[i] + 'a';
                dfs(k, depth + 1);
            }
            if (cnt >= 100) return;
        }
    }
}

int main(void) {
    //freopen("i.in", "r", stdin);
    //freopen("o.ot", "w", stdout);
    int i;
    int j;
    int x = 1;

    for ( ; cin >> N && N != 0; ) {
        char ch;

        cd.clear();
        memset(let, -1, sizeof(let));
        char bs[10];

        for (i = 0; i < N; i++) {
            scanf("%s%s", bs, bag[i]);

            let[bs[0]-'a'] = i;
        }
        j = 0;
        for (i = 0; i < 26; i++) {
            if (let[i] != -1) {
                mapp[j] = let[i], let[j] = i;
                j++;
            }
        }

        scanf("%s", S);

        printf("Case #%d\n", x++);

        cnt = 0;
        dfs(0, 0);
        cout << "\n";
    }
    return 0;
}
