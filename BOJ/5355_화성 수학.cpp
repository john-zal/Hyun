#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	string s;
	float num = 0.2f;
	char command;

	getline(cin, s);
	T = stoi(s);
	while (T--)
	{
		getline(cin, s);
		int idx = s.find(' ');
		num = stof(s.substr(0, idx));
		s = s.substr(idx + 1, s.size());
		
		int i = -2;
		while ((i+=2) <= s.size())
		{
			command = s[i];
			switch (command)
			{
			case '@': //3 °öÇÏ±â
				num *= 3;
				break;
			case '%': //5 ´õÇÏ±â
				num += 5;
				break;
			case '#': //7 »©±â
				num -= 7;
				break;
			}
		}
		printf_s("%.2f\n", num);
	}
}