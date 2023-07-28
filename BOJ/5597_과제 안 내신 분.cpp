#include <iostream>

using namespace std;

int main()
{
	bool arr[31] = { false };

	int n = 28;

	while(n--)
	{
		int num;
		cin >> num;
		arr[num] = true;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (!arr[i])
			cout << i << '\n';
	}
	
	return 0;
}