#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define MAXN 60

int ans;
string a, b;

int main(void) {
    while(getline(cin, a) && getline(cin, b)) {
        int ans = 0;
        if(a.size() > b.size()) swap(a, b);
        for(int i = 0; i < a.size(); i++) {
            for(int j = 1; i + j <= a.size(); j++) {
                if(b.find(a.substr(i, j)) != string::npos) {
                    ans = max(ans, j);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
