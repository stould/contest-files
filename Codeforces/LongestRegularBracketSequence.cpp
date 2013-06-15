#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <stdio.h>
#include <string.h>

using namespace std;

char str[1000007];
int s[1000007], st, N, ans;
map<int, int> mp;

int main(void) {
    freopen("i.in", "r", stdin);

    scanf("%s", str);

    N = strlen(str);
    st = ans = 0;

    for(int i = 0; i < N; i++) {
        if(str[i] == '(') {
            s[st++] = i;
        } else {
            if(st != 0) {
                int len = i - s[--st] + 1;
                mp[len] += 1;
                if(len > ans) {
                    ans = len;
                }
            }
        }
    }
    if(ans == 0) mp[ans] = 1;
    printf("%d %d\n", ans, mp[ans]);
    return 0;
}
