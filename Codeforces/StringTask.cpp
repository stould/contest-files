#include <iostream>
#include <cctype>

using namespace std;

bool isLatinVowel(char temp) {
	if(temp == 'a') {
		return true;
	} else if(temp == 'o') {
		return true;
	} else if(temp == 'y') {
		return true;
	} else if(temp == 'e') {
		return true;
	} else {
		return false;
	}
}

int main() {
	string s;
	
	getline(cin, s);
	
	string::iterator it;
	
	for(unsigned i = 0; i < s.size(); i++) {		
		s[i] = tolower(s[i]);
		if(isLatinVowel(s[i])) {
			s.erase(i, i + 1);
		}
	} 
	
	bool test = true;
	for(unsigned i = 0; i < s.size(); i++) {		
		if(test) {
			s.insert(i, ".");
			test = false;
		} else {
			test = true;
		}
	}	
	
	cout << s << endl;
	
	return 0;
}
