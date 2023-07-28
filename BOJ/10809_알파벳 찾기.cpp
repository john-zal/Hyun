#include <iostream>
#include <string>

using namespace std;

int main()
{
	int AlphaArr[26];
	for (int i = 0; i < 26; i++)
		AlphaArr[i] = -1;

	string s;
	cin >> s;

	for (int i = 0; i < (int)s.size(); i++)
	{
		if (AlphaArr[s[i] - 'a'] == -1)
			AlphaArr[s[i] - 'a'] = i;
	}
		

	for (int i = 0; i < 26; i++)
		cout << AlphaArr[i] << " ";
	
	return 0;
}