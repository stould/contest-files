#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <stdio.h>

using namespace std;

struct Page {
    string name;
    vector<int> p;

    Page(string _name, int v) {
        name = _name;
        p = vector<int>();
        p.push_back(v);
    }

    bool operator<(const Page& p) const {
        return name < p.name;
    }
};

vector<Page> v;

int main(void) {
    string style;

    v.clear();

    int i, j, page;
    while(cin >> style >> page) {
        int index = -1;
        for(i = 0; i < (int) v.size(); i++) {
            if(v[i].name == style) {
                index = i;
                v[i].p.push_back(page);
                break;
            }
        }
        if(index == -1) {
            v.push_back(Page(style, page));
        }
    }
    sort(v.begin(), v.end());

    for(i = 0; i < (int) v.size(); i++) {
        cout << v[i].name << endl;
        sort(v[i].p.begin(), v[i].p.end());
        for(j = 0; j < (int) v[i].p.size() - 1; j++) {
            cout << v[i].p[j] << " ";
        }
        cout << v[i].p[j] << endl;
    }
    return 0;
}
