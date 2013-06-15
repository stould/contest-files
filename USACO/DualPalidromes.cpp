/*
ID: jeferso1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

bool isPalindrome(string s) {
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

string toBase(int base, int value) {
    string v = "0123456789ABCDEFGHIJ";
    string result = "";

    while(value > 0) {
        result += v[value % base];
        value /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    int N, S, ct = 0;
    stringstream ss;

    scanf("%d %d", &N, &S);

    int last = S + 1;

    for(int j = last; ct < N; j++) {
        int checker = 0;
        for(int k = 2; k <= 10; k++) {
            string tmp = toBase(k, j);
            if(isPalindrome(tmp)) {
                checker++;
            }
        }
        if(checker >= 2) {
            cout << j << endl;
            ct++;
        }
    }
}
