#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	string s, s2;
	cin >> s >> s2;
	
	int A = 0;
	int B = 0;
	for (int i = 0; i < 3; i++)
	{
		A += (s[i] - '0') * (int)pow(10, i);
		B += (s2[i] - '0') * (int)pow(10, i);
	}

	cout << max(A, B);

	return 0;
}