#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
 
using namespace std;
 
long long i, j, n, x;
string s;
 
void print(long long ma, long long mi) {
    cout << "The maximum and minimum are " << ma << " and " << mi << "." << endl;
}
 
int main(void) {
    cin >> n;
    for(x = 0; x < n; x++) {
        cin >> s;
        long long ma = 1, mi = 0;
        vector<long long> nums; vector<char> op;
        for(i = 0; i < s.size(); i++) {
            if(s[i] == '+') {
                op.push_back('+');
                int a = 0, b = 0, base = 0;
                j = i - 1;
                while(j >= 0 && s[j] != '+' && s[j] != '*') {
                    a += (s[j] - '0') * pow(10, base++);
                    j--;
                }
                base = 0, j = i + 1;
                while(j < s.size() && s[j] != '+' && s[j] != '*') {
                    j++;
                }
                j -= 1;
                while(j >= 0 && s[j] != '+' && s[j] != '*') {
                    b += (s[j] - '0') * pow(10, base++);
                    j--;
                }
                if(nums.size() > 0) {
                    nums.push_back(b);
                } else {
                    nums.push_back(a); nums.push_back(b);
                }
            } else if(s[i] == '*') {
                op.push_back('*');
                int a = 0, b = 0, base = 0;
                j = i - 1;
                while(j >= 0 && s[j] != '+' && s[j] != '*') {
                    a += (s[j] - '0') * pow(10, base++);
                    j--;
                }
                base = 0, j = i + 1;
                while(j < s.size() && s[j] != '+' && s[j] != '*') {
                    j++;
                }
                j -= 1;
                while(j >= 0 && s[j] != '+' && s[j] != '*') {
                    b += (s[j] - '0') * pow(10, base++);
                    j--;
                }
                if(nums.size() > 0) {
                    nums.push_back(b);
                } else {
                    nums.push_back(a); nums.push_back(b);
                }
            }
        }
        int b = 0;
        vector<char> opmin = op;
        vector<long long> tmin = nums;
        while(1) {
            int b = 0, has = 0;
            for(i = 0; i < tmin.size() - 1; i++) {
                if(opmin[b] == '*') {
                    has = 1;
                    long long tmp = tmin[i]*tmin[i + 1];
                    tmin.erase(tmin.begin() + i);
                    tmin.erase(tmin.begin() + i);
                    tmin.insert(tmin.begin() + i, tmp);
                    opmin.erase(opmin.begin()+b);
                    break;
                }
                b++;
            }
            if(!has) {
                for(i = 0; i < tmin.size() ; i++) {
                    mi += tmin[i];
                }
                break;
            }
        }
        b = 0;
        vector<char> opmax = op;
        vector<long long> tmax = nums;
        while(1) {
            int b = 0, has = 0;
            for(i = 0; i < tmax.size() - 1; i++) {
                if(opmax[b] == '+') {
                    has = 1;
                    long long tmp = tmax[i]+tmax[i + 1];
                    tmax.erase(tmax.begin() + i);
                    tmax.erase(tmax.begin() + i);
                    tmax.insert(tmax.begin() + i, tmp);
                    opmax.erase(opmax.begin()+b);
                    break;
                }
                b++;
            }
            if(!has) {
                for(i = 0; i < tmax.size() ; i++) {
                    ma *= tmax[i];
                }
                break;
            }
        }
        set<char> s(op.begin(), op.end());
        if(s.size() == 1) {
            if((*s.begin()) == '*') {
                mi = 0;
            } else {
                ma = 0;
            }
        }
        print(ma, mi);
    }
}
