#include <iostream>
using namespace std;

int main()
{
	int input,n;
	int a, b,c;
	int cycle=0;

	cin >> input;
	n = input;

	do{
		a = n / 10;
		b = n % 10;
		c = (a + b) % 10;
		n = b * 10 + c;
		cycle += 1;
	} 	while (!(n == input));

	cout << cycle;
}