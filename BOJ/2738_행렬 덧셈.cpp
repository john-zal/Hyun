#include <iostream>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int arr1[10001] = {};
	int arr2[10001] = {};

	for (int i = 0; i < N * M; i++)
		cin >> arr1[i];
	
	for (int i = 0; i < N * M; i++)
		cin >> arr2[i];

	for (int i = 0; i < N * M; i++)
	{
		cout << arr1[i] + arr2[i];	
		((i + 1) % M == 0) ? cout << '\n' : cout << " ";
	}
}