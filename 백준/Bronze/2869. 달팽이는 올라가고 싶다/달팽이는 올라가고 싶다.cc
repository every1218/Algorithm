#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0, v = 0;

	cin >> a >> b >> v;

	int day=1;

	if (a >= v)
		cout << day << endl;
	else {
		if ((v - a) % (a - b)!=0){ 
			day++;
		}
		day += (v - a) / (a - b);
		cout << day << endl;
	}
}