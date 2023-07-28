#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int count = 0;

	for (char c : s)
	{
		if (c == ' ')
			count++;
	}

	if (s[0] == ' ')
		count--;
	if (s[s.size() - 1] == ' ')
		count--;

	cout << count+1;
	return 0;
}