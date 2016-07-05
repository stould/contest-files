#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;

string funcD(int n, int b) {
    if(n == 0) return "0";
    string chars = "0123456789ABCDEFGHIJ";
    string result = "";

    int nn = abs(n);
    while(nn > 0) {
        result = chars[nn % b] + result;
        nn /= b;
    }
    reverse(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++) {
        if(result[i] == '1') result[i] = '-';
        if(result[i] == '2') result[i] = '+';
    }
    if(n < 0) {
        reverse(result.begin(), result.end());
    }
    return result;
}


int main(void) {
    freopen("i.in", "r", stdin);
    freopen("setun.out", "w", stdout);
    while(~scanf("%d", &n)) {
        printf("%s\n", funcD(n, 3).c_str());
    }
    return 0;
}
