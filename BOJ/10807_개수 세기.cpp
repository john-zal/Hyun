#include <iostream>

using namespace std;

int main()
{
	int arr[101];
	for (int i = 0; i < 101; i++)
		arr[i] = -111;

	int N, v, sum;
	sum = 0;
	
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	cin >> v;

	for (int i = 0; i < N; i++)
	{
		if (arr[i] == v)
			sum++;
	}

	cout << sum << '\n';

	return 0;
}