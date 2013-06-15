#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;

vector<string> split(string source, string pattern) {
    unsigned i, base = 0;
    vector<string> ret;
    string buff;

    for(i = 0; i < source.size(); i++) {
        if(source.substr(i, pattern.size()) == pattern) {
            ret.push_back(buff);
            i += pattern.size() - 1;
            buff.clear();
        } else {
            buff += source[i];
        }
    }
    ret.push_back(buff);
    return ret;
}

int main(void) {
    cin >> n;
    string actual = "/", get;
    for(int i = 0; i < n; i++) {
        getline(cin, get);
        if(get.substr(0, 3) == "pwd") {
            cout << actual << endl;
        } else {
            string path = get.substr(4, get.size() - 4);
            vector<string> dir = split(path, "/");
            if(!count(dir.begin(), dir.end(), "..")) {
                actual = path;
            } else {
                string now = actual;
                for(int i = 0; )
            }
        }
    }
    return 0;
}
