#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    int n, m;
    vector<string> memo;

    cin >> n >> m;

    while(m > 0) {
        string s;
        getline(cin, s);

        istringstream ss(s);

        char c;
        int a, b;

        ss >> c >> a >> b;

        string ra = a + " " + b;
        string rb = b + " " + a;

        if(c == 'F') {
            memo.push_back(ra);
            memo.push_back(rb);
        } else {
            vector<string>::iterator p1 = find(memo.begin(), memo.end(), ra);
            vector<string>::iterator p2=  find(memo.begin(), memo.end(), rb);
            if(p1 == 0|| p2 == 0) {
                cout << "S";
            } else {
                cout << "N";
            }
        }
        m--;
    }


    return 0;
}
