#include <iostream>
#include <cctype>

using namespace std;

string g;

int main(void) {
    getline(cin, g);

    for(int i = 0; i < (int) g.size(); i++) {
        if(g[i] >= 'a' && g[i] <= 'z') {
            g[i] = toupper(g[i]);
        }
    }
    cout << g << endl;
    return 0;
}
