#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 1; ; i++)
	{
		//n * 3(n-1)
		int sum = i * (3 * (i - 1)) + 1;
		if (sum >= N)
		{
			cout << i;
			break;
		}	
	}
}