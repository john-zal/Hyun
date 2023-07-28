#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T, R;
	string s;
	string convert = "";
	cin >> T;
	while (T--)
	{
		cin >> R >> s;
		
		for (char c : s)
		{
			for (int i = 0; i < R; i++)
				convert += c;	
		}
		convert += '\n';
	}

	cout << convert;

	return 0;
}