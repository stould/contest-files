#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace std;

int i, j, n, t = 1;
string s;

int main(void) {
    while(1) {
        cin >> n;
        if(!n) break;
        cin >> s;

        int sum = 0;

        for(i = 0; i < s.size() && s[i] != '+' && s[i] != '-'; i++){}

        sum = atoi(s.substr(0, i+1).c_str());

        for(; i < s.size(); i++) {
            int j = i;
            char operand = s[j - 1];

            while(j < s.size() && s[j] != '+' && s[j] != '-') {
                j += 1;
            }
            if(i == j) continue;

            int val = atoi(s.substr(i, j - i + 1).c_str());

            if(operand == '+') {
                sum += val;
            } else {
                sum -= val;
            }
            i = j;
        }
        cout << "Teste " << t << endl << sum << endl;
        t += 1;
    }
}
