#include <iostream>

using namespace std;

int main()
{
	int data[3] = {}; // max, За, ї­

	int arr[81] = {};

	for (int i = 0; i < 81; i++)
	{
		cin >> arr[i];
		if (data[0] < arr[i])
		{
			data[0] = arr[i];
			data[1] = i / 9;
			data[2] = i % 9;
		}
	}
	cout << data[0] << '\n' << data[1] +1 << ' ' << data[2] +1 << '\n';
}