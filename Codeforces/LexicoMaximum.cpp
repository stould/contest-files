#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

char ok[100005];

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%s", ok);
    string ans = "";
    int j, last = 0;
    for(char c = 'z'; c >= 'a'; c--) {
        int id = -1;
        for(j = last; j < strlen(ok); j++) {
            if(ok[j] == c) {
                ans += c;
                id = j;
            }
        }
        if(id != -1) {
            last = id;
        }
    }
    cout << ans << endl;
    return 0;
}
