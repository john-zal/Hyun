#include <bits/stdc++.h>
using namespace std;

vector<int> length;
int sum = 0;
int spy[2] = {};

void Seven_Members() 
{
	sum -= 100;

	for (int i = 0; i < length.size()-1; i++)
	{
		for (int j = i+1; j < length.size(); j++)
		{
			if (length[i] + length[j] == sum) 
			{
				spy[0] = length[i];
				spy[1] = length[j];
				return;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		int temp = 0;
		cin >> temp;
		length.push_back(temp);
		sum += length[i];
	}
	
	Seven_Members();

	sort(length.begin(), length.end());

	for (int i = 0; i < length.size(); i++)
	{
		if (length[i] != spy[0] && length[i] != spy[1])
		{
			cout << length[i] << endl;
		}
	}
	return 0;
}