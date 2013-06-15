#include <iostream>
#include <fstream>

using namespace std;

string a, b;
int ans = 0;

int main(void) {
    ifstream is("i.in");
    ofstream os("o.out");

    is >> a >> b;

    for(int i = 0; i < (int) a.size(); i++) if(a[i] != b[i]) ans += 1;

    os << ans << "\n";

    os.close();
    return 0;
}
