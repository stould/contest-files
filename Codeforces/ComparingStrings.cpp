#include <iostream>
#include <map>

using namespace std;

string a, b;
map<char, int> ca, cb;

int main(void) {
    cin >> a >> b;

    if(a.size() != b.size()) {
        cout << "NO" << endl; return 0;
    }

    for(int i = 0; i < (int) a.size(); i++) {
        ca[a[i]] += 1;
    }

    for(int i = 0; i < (int) b.size(); i++) {
        cb[b[i]] += 1;
    }
    bool eq = true;

    for(char c = 'a'; c <= 'z'; c++) {
        if(ca[c] != cb[c]) {
            eq = false;
        }
    }

    int ct = 0;
    for(int i = 0; i < (int) a.size(); i++) {
        if(a[i] != b[i]) ct++;
    }


    if(eq && ct == 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


    return 0;
}
