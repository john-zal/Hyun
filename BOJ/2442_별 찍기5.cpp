#include <iostream>
using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		//°ø¹é N-i°³
		for (int j = 0; j < N - i; j++)
			cout << " ";

		for (int j = 0; j <(i*2) -1; j++)
			cout << "*";

		if(i != N)
			cout << '\n';
	}
	return 0;
}