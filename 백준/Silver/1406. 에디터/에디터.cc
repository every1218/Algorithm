#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack <char> lef; //left 
	stack <char> rig; //rihgt
	string arr ;
	cin >> arr;
	int num;
	cin >> num;
	
	for (int i = 0; i < arr.length();i++) {
		lef.push(arr[i]);
	}
	
	while (num--) {
		char input;
		cin >> input;
		
		if (input == 'L') {
			if(!lef.empty()){
				rig.push(lef.top());
				lef.pop();
			}
		}
		else if (input == 'D') {
			if (!rig.empty()){
				lef.push(rig.top());
				rig.pop();
			}
		}
		else if (input == 'B') {
			if(!lef.empty())
				lef.pop();
		}
		else if (input == 'P') {
			char ch;
			cin >> ch;
			lef.push(ch);
		}
	}
	
	while (!lef.empty()) {
		//cout << lef.top(); -> ydcba(커서)x 나옴 -> 해답봄
		rig.push(lef.top()); //<-이거구나 ㄲㅂ
		lef.pop();
	}
	
	while (!rig.empty()) {
		cout << rig.top();
		rig.pop();
	}
}
