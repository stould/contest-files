#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

typedef long long ll;
typedef long double ld;

map<char, char> rev;

void mount() {
    rev['A'] = 'A';
    rev['B'] = '$';
    rev['C'] = '$';
    rev['C'] = '$';
    rev['D'] = '$';
    rev['E'] = '3';
    rev['F'] = '$';
    rev['G'] = '$';
    rev['H'] = 'H';
    rev['I'] = 'I';
    rev['J'] = 'L';
    rev['K'] = '$';
    rev['L'] = '$';
    rev['M'] = 'M';
    rev['N'] = '$';
    rev['O'] = 'O';
    rev['P'] = '$';
    rev['Q'] = '$';
    rev['R'] = '$';
    rev['S'] = '2';
    rev['T'] = 'T';
    rev['U'] = 'U';
    rev['V'] = 'V';
    rev['W'] = 'W';
    rev['X'] = '$';
    rev['Y'] = 'Y';
    rev['Z'] = '5';
    rev['1'] = '1';
    rev['2'] = 'S';
    rev['3'] = 'E';
    rev['4'] = '$';
    rev['5'] = 'Z';
    rev['6'] = '$';
    rev['7'] = '$';
    rev['8'] = '8';
    rev['9'] = '$';
}

int i;

vector<string> v;
string tmp;

bool isNone(string);
bool isMirrored(string);
bool isMirroredAndPalindrome(string);
bool isPalindrome(string);

int main(void) {
    mount();
    while(cin >> tmp) v.push_back(tmp);
    REP(i, v.size()) {
        if(!isPalindrome(v[i]) && !isMirrored(v[i])) {
            cout << v[i] << " -- is not a palindrome." << endl << endl;
        } else if(isPalindrome(v[i]) && !isMirrored(v[i])) {
            cout << v[i] << " -- is a regular palindrome." << endl << endl;
        } else if(isMirrored(v[i]) && !isPalindrome(v[i])) {
            cout << v[i] << " -- is a mirrored string." << endl << endl;
        } else {
            cout << v[i] << " -- is a mirrored palindrome." << endl << endl;
        }
    }
    return 0;
}

bool isNone(string s) {
   return false;
}

bool isPalindrome(string s) {
    int i;
    REP(i, s.size()) {
        if(s[i] != s[s.size() - 1 - i]) return false;
    }
    return true;
}

bool isMirrored(string s) {
    int i;
    REP(i, s.size()) {
        if(rev[s[i]] != s[s.size() - i - 1] && rev[s[s.size() - i - 1]] != s[i]) return false;
    }
    return true;
}
