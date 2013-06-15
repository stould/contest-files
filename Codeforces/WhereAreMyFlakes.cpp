#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int i, n, m, a;
char s[10];
string str;
bool checked[10010];

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d%d", &n, &m);
    getline(cin, str);
    for(i = 1; i <= m; i++) {
        getline(cin, str);
        sscanf(str.c_str(), "%*s%*s%s%*s%d", s, &a);
        if(strcmp(s, "right")) {
            if(a + 1 > n) {
                valid = false;
            } else {

            }
        } else {

        }
    }
    return 0;
}
