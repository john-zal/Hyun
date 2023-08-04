#include <iostream>
#include <string>

using namespace std;

int cnt = 0;
bool isUsed[26];

void ClearArr()
{
	for (int i = 0; i < 26; i++)
		isUsed[i] = false;
}

void check(string& s)
{
	if (isUsed[s[0] - 'a'])
	{
		ClearArr();
		return;
	}
		
	if (s == "")
	{
		cnt += 1;
		ClearArr();
		return;
	}

	isUsed[s[0] - 'a'] = true;


		while (s[0] == s[1])
			s = s.substr(1, s.size());

		s = s.substr(1, s.size());

	check(s);
}

int main()
{
	string s;
	int n;
	cin >> n;
	while (n--)
	{
		cin >> s;
		check(s);
	}

	cout << cnt;
}