#include <iostream>

using namespace std;

int main()
{
	int basket, ballCount;
	int basketArr[102] = { 0 };
	
	cin >> basket >> ballCount;

	for (int i = 0; i < ballCount; i++)
	{
		int start, end, ballNum;
		cin >> start >> end >> ballNum;

		for (int j = start; j <= end; j++)
			basketArr[j] = ballNum;
	}

	for (int i = 1; i <= basket; i++)
		cout << basketArr[i] << " ";

	cout << '\n';

	return 0;
}