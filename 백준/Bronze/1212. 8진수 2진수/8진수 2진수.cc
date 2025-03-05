#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	string first[8] = { "","1","10","11","100","101","110","111" };
	string eight[8] = {"000","001","010","011","100","101","110","111" };

	cin >> str;
	bool start = 1;
	
	if (str.length() == 1 && str[0] - '0' == 0) {
		cout << "0";
	}

	for (int i = 0; i < str.length(); i++) {
		int a = str[i] - '0';

		if (start) {
			cout << first[a];
			start = 0;
		}
		else
			cout << eight[a];
	}
}