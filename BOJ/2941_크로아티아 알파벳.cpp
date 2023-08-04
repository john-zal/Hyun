#include <iostream>
#include <string>
using namespace std;
int cnt = 0;

void CheckAlpha(string& s)
{
	if (s == "")
		return;

	switch (s[0])
	{
	case 'c':
		if (s[1] == '=' || s[1] == '-')
			s = s.substr(2, s.size());
		else
			s = s.substr(1, s.size());
		break;
	case 'd':
		if (s[1] == '-')
			s = s.substr(2, s.size());
		else if (s[1] == 'z' && s[2] == '=')
			s = s.substr(3, s.size());
		else
			s = s.substr(1, s.size());
		break;
	case 'l':
		if (s[1] == 'j')
			s = s.substr(2, s.size());
		else
			s = s.substr(1, s.size());
		break;
	case 'n':
		if (s[1] == 'j')
			s = s.substr(2, s.size());
		else
			s = s.substr(1, s.size());
		break;
	case 's':
		if (s[1] == '=')
			s = s.substr(2, s.size());
		else
			s = s.substr(1, s.size());
		break;
	case 'z':
		if (s[1] == '=')
			s = s.substr(2, s.size());
		else
			s = s.substr(1, s.size());
		break;
	default:
		s = s.substr(1, s.size());
		break;
	}
	cnt++;
	CheckAlpha(s);
}

int main()
{
	string s = "ABCDEF";
	cin >> s;
	CheckAlpha(s);
	cout << cnt;

}