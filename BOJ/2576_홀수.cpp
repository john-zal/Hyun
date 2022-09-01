#include "bits/stdc++.h"
using namespace std;

int main() 
{
	int arr[7] = {};
	int min = INT_MAX;
	int cnt = 0;
	for (int i = 0; i < 7; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 7; i++)
	{
		if (arr[i] % 2 == 1)
		{
			if (min > arr[i])
			{
				min = arr[i];
			}
			cnt += arr[i];
		}
	}
	if (min == INT_MAX)
	{
		min = -1;
		cout << min << endl;
		return 0;
	}
	cout << cnt << endl;
	
	cout << min << endl;
	return 0;
}