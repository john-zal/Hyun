#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n, k;
bool isUsed[10];
vector<int> numVec;
vector<int> buf;
vector<string> numTable;

void Rec(int num)
{
	if (num == k)
	{
		string s;

		for (int i = 0; i < buf.size(); i++)
			s += to_string(buf[i]);

		if (numTable.empty())
			numTable.push_back(s);
		else
		{
			bool check = false;
			for (int i = 0; i < numTable.size(); i++)
			{
				if (numTable[i] == s)
					return;
			}
				numTable.push_back(s);
		}
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!isUsed[i])
		{
			isUsed[i] = true;
			buf.push_back(numVec[i]);
			Rec(num + 1);
			isUsed[i] = false;
			buf.pop_back();
		}
	}
}

int main()
{
	cin >> n >> k;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		numVec.push_back(num);
	}

	Rec(0);
	cout << numTable.size();
}