#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

int i, j, d, n, x;
char c[100010];
char o[3] = {'{', '[', '('};
char e[3] = {'}', ']', ')'};

int main(void) {
    scanf("%d", &n);
    for(x = 0; x < n; x++) {
        scanf("%s", c);
        stack<char> s;
        d = strlen(c);
        bool ok = true;
        for(i = 0; i < d; i++) {
            bool flag1 = false, flag2 = false;
            char a = 'a';
            if(!s.empty()) {
                a = s.top();
            }

            for(j = 0; j < 3; j++) {
                if(c[i] == o[j]) {
                    flag1 = true;
                }
            }
            if(flag1) {
                s.push(c[i]); continue;
            } else {
                for(j = 0; j < 3; j++) {
                    if(o[j] == a && c[i] == e[j]) flag2 = true;
                }
            }
            if(!flag2) {
                ok = false; break;
            } else {
                s.pop();
            }
        }
        if(ok && s.size() == 0 ) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
    return 0;
}
