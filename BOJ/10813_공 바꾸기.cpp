#include <iostream>

using namespace std;

int main()
{
	int arr[102] = { 0 };
	int basket, ballCount;

	cin >> basket >> ballCount;

	for (int i = 1; i <= basket; i++)
		arr[i] = i;

	for (int i = 0; i < ballCount; i++)
	{
		int start, end;
		cin >> start >> end;

		if (start == end)
			continue;

		int temp = arr[start];

		arr[start] = arr[end];
		arr[end] = temp;
	}

	for (int i = 1; i <= basket; i++)
		cout << arr[i] << " ";
	
		cout << '\n';

	return 0;
}