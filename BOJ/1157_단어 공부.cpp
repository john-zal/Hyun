#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int Alphabet[26] = {};
int MAX = 0;
int DUPLE = 0;

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] < 'a')
			s[i] += 32;

		Alphabet[s[i] - 'a'] += 1;

		if (Alphabet[s[i] - 'a'] > Alphabet[MAX])
			MAX = s[i] - 'a';
	}

	for (int i = 0; i < 26; i++)
	{
		if (Alphabet[i] == Alphabet[MAX])
			DUPLE += 1;

		if (DUPLE > 1)
		{
			cout << "?\n";
			return 0;
		}		
	}

	cout << (char)('a' + MAX - 32) << endl;
}