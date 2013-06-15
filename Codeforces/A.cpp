#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
	int min, hour;
	scanf("%d:%d", &min, &hour);

	for(int i = hour + 1; i <= 23; i++) {
		for(int j = min + 1; j <= 59; j++) {
			if(i / 10 == j % 10 && j / 10 == i % 10) {
				string ret = "";
				if(i <= 9) {
					ret += "0"+i;
				} else {
					ret += i;
				}
				if(j <= 9) {
					ret += "0"+j;
				} else {
					ret += j;
				}
				cout << ret << endl;
				return 0;
			}
		}
	}
	return 0;
}
