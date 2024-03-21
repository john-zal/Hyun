#include <iostream>

using namespace std;

int main()
{
	int tc , option, cnt;
	cin >> tc;
	while (tc--)
	{
		int cost, option;
		cin >> cost >> option;
	
		for (int i = 0; i < option; i++)
		{
			int optionCost;
			cin >> cnt >> optionCost;
			cost += cnt * optionCost;
		}

		cout << cost << '\n';
	}
}