#include <iostream>
using namespace std;

#include <list>
#include <string>

int main()
{
	int L = 0;
	cin >> L;
	string input = "";
	
	for (int i = 0; i < L; i++)
	{
		cin >> input;
		list<char> output;
		list<char>::iterator iter = output.begin();

		for (char c : input)
		{
			switch (c)
			{
			case '<':
				if (iter != output.begin())
					iter--;
				break;
			case '>' :
				if (iter != output.end())
					iter++;
				break;
			case '-' :
				if (iter != output.begin())
				{
					iter--;
					iter = output.erase(iter);
				}
					
				break;
			default:
				output.insert(iter, c);
				break;
			}
		}

		for (auto i : output)
			cout << i;

		cout << '\n';
	}
	return 0;
}