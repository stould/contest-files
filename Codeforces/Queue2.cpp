#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    string name;
    int h;
    int a;

    Person() { }

    Person(string _name, int _h) {
        name = _name;
        h = _h;
    }
    bool operator<(const Person p) const {
        if(h == p.h) {
            return name < p.name;
        }
        return h < p.h;
    }
};

int main() {
    int N;

    cin >> N;

    vector<Person> names(N);
    int height = 1;
    for(int i = 0; i < N; i++) {
        cin >> names[i].name >> names[i].h;
        names[i].a = height++;
    }
    sort(names.begin(), names.end());

    bool stop = false;

    for(int i = 0; i < (int) names.size(); i++) {
        if(names[i].h > i) {
            stop = true;
            break;
        }
    }

    if(stop) {
        cout << "-1" << endl;
    } else {
        for(int i = 0; i < N; i++) {
            if(names[i].h == N - i) {
                names.insert(names.begin() + names[i].h, names[i]);
                names.erase(names.begin() + i);
            }
        }
        for(int i = 0; i < N; i++) {
            cout << names[i].name << " " << names[i].a << endl;
        }
    }
    return 0;
}
