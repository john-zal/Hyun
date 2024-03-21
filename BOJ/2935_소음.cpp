#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string a;
	char oper;
	string b;
	cin >> a >> oper >> b;

	string c = a.size() > b.size() ? a : b;
	string d = a.size() < b.size() ? a : b;

	if (a.size() == b.size())
	{
		c = a > b ? a : b;
		d = a < b ? a : b;
	}

	string answer = "";
	switch (oper)
	{
	
	case '+' :
		if (c.size() == 1)
			answer = to_string(stoi(c) + stoi(d));
		else
		{
			c[c.size() - d.size()] += (d[0]-'0');
			answer = c;
		}		
		break;
	case '*' :
		if (c.size() == 1)
			answer = to_string(stoi(c) * stoi(d));
		else
		{
			for (int i = 0; i < d.size() - 1; i++)
				c.append("0");

			answer = c;
			if (d[0] == '0')
				answer = '0';
		}
		break;
	}
	cout << answer;

}