#include <iostream>
#include <string>
#include <map>

using namespace std;

string XYZ[3];
int k;

map<string, int> table;
string buf;

void Rec(int num, int idx, const string& s)
{
	if (idx == k)
	{
		table[buf]++;
		return;
	}

	for (int i = num; i < s.size(); i++)
	{
		buf.push_back(s[i]);
		Rec(i + 1, idx + 1, s);
		buf.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> XYZ[0] >> XYZ[1] >> XYZ[2] >> k;

	for (int i = 0; i < 3; i++)
		Rec(0, 0, XYZ[i]);

	int cnt = 0;

	//pair<string, int>
	for (auto i : table)
	{
		if (i.second > 1)
		{
			cout << i.first << '\n';
			cnt++;
		}
	}

	if (!cnt)
		cout << -1;	
}