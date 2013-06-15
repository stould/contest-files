#include <iostream>
#include <stdio.h>

using namespace std;

string s;
int a = 0, c = 0, g = 0, t = 0;

int main(void) {
    freopen("i.in.c", "r", stdin);
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i]=='A') a++;
        if(s[i]=='C') c++;
        if(s[i]=='G') g++;
        if(s[i]=='T') t++;
    }
    cout << a << " " << c << " " << g << " " << t << "\n";
    return 0;
}
