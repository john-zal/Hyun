#include <iostream>
using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
			cout << " ";

		for (int j = 0; j < ((N - i) * 2) - 1; j++)
			cout << "*";

		cout << '\n';
	}

	for (int i = N-2; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
			cout << " ";

		for (int j = 0; j < ((N - i) * 2) - 1; j++)
			cout << "*";

		cout << '\n';
	}
	return 0;
}