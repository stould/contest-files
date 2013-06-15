#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string tim;
int hour, minute;

bool palindrome(string s) {
    for(int i = 0; i < (int) s.size(); i++) {
        if(s[i] != s[s.size() - 1 - i]) return false;
    }
    return true;
}

int main(void) {
    cin >> tim;

    stringstream ss;

    ss << tim.substr(0, 3);
    ss >> hour;
    ss.clear();
    cout << hour << endl;
    ss << tim.substr(3, 3);
    ss >> minute;
    ss.clear();
    cout << minute << endl;
    minute++;

    while(1) {
        for(; ; hour++) {
            if(hour == 24) hour = 0;
            for(; ; minute++) {
                if(minute == 60) minute = 0;
                string test = "";
                if(hour <= 9) test += "0";
                ss.clear();
                ss << hour;
                ss >> test;
                ss.clear();
                test += ":";
                if(minute <= 9) test += "0";
                ss.clear();
                ss << minute;
                ss >> test;
                ss.clear();
                cout << test << endl;
                if(palindrome(test)) { cout << test << endl; goto end; }
            }
        }
    }
    end:;
    return 0;
}

