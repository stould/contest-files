/*
ID: jeferso1
LANG: C++
TASK: palsquare
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

string toBase(int base, long long value) {
    string v = "0123456789ABCDEFGHIJ";
    string result = "";

    while(value > 0) {
        result += v[value % base];
        value /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

bool isPalindrome(string s) {
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int N;
    scanf("%d", &N);

    for(long long i = 1L; i <= 300L; i++) {
        long long p = i * i;
        string b = toBase(N, i);
        string exp = toBase(N, p);

        if(isPalindrome(exp)) {
            cout << b << " " << exp << endl;
        }
    }
    return 0;
}
