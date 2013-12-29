#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

int in() { int x; scanf("%d", &x); return x; }

using namespace std;

int T;
string str;

bool func(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(void) {
    T = in();
    
    int i;
    
    cin.ignore();
    
    for ( ; T--; ) {
        int vowel = 0;
        int sum = 0;
        
        getline(cin, str);
        
        for (i = 0; i < (int) str.size(); i++) {
            if (str[i] == ' ') {
                str = str.substr(0, i) + str.substr(i + 1, str.size() - i);
            }
        }
       
        for (i = 0; i < (int) str.size(); i++) {
            if (func(str[i])) vowel += 1;
            
            if (i > 0) sum += abs(str[i] - str[i - 1]);
        }
        
        if (str.size() != 1) sum += abs(str[0] - str[str.size() - 1]);
        
        printf("%d\n", vowel * sum);
    }
    
    return 0;
}
