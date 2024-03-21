#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	//ÄõÅÍ 0.25 ´ÙÀÓ 0.10 ´ÏÄÌ 0.05, Æä´Ï 0.01
	const int money[4] = { 25, 10, 5, 1 };
	while (T--)
	{
		int cost;
		cin >> cost;

		for (int i = 0; i < 4; i++)
		{
			cout << cost / money[i];
			i != 3 ? cout << " " : cout << "\n";			
			cost %= money[i];
		}
	}
}