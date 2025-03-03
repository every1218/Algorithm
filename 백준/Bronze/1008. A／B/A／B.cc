#include <iostream>
using namespace std;

int main()
{
	double a, b;
    scanf("%lf %lf", &a, &b);	
    printf("%.13lf", a / b);	// 유효숫자가 13개 

    return 0;
}

