#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	string s;
	int n;
	cin >> s >> n;

	int sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int num = 0;
		if (s[i] > 47 && s[i] < 58)
			num = (int)(s[i] - 48);
		else if (s[i] > 64 && s[i] < 91)
			num = (int)(s[i] - 55);
		//ÀÚ¸´¼ö*(Áø¼ö^)
		sum += num * (int)pow(n, (int)s.size() - 1 - i);
	}
	
	cout << sum;
}