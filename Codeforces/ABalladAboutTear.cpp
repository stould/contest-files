#include <bits/stdc++.h>
using namespace std;

string s;
char c;
int m, x;

int main(void) {
    cin >> s >> m;
    
    int ans = 0;
    bool ok = false;
    
    for(int i=0; !ok && i < (int) s.size(); i++) {
        if (i + 7 > s.size()) break;
//      cout << s.substr(i, 7) << "\n";
        if (s.substr(i, 7) == "desmond") {
            ok = true;
        }
    }   
    for(int i=0; !ok && i < m; i++) {
        cin >> x >> c;
        ans++;  
    
        s[x-1] = c;
        for (int j = 0; j < 7; j++) {
            if (x - 1 - j >= 0 && x - 1 - j + 7 <= (int) s.size()) {
//              cout << s.substr(x - 1 - j, 7) << "\n";
                if (s.substr(x - 1 - j, 7) == "desmond") {
                    ok = 1;
                }
            }
        }
    } 
    
    if(ok) {
        cout << "I love you, Desmond!\n";
        cout << ans << "\n";    
    }
    else {
        cout << "Goodbye, my love!\n";  
    }



    return 0;
}

