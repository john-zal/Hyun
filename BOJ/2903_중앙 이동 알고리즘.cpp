#include <iostream>
using namespace std;

int main()
{
	int N;
	int initPoint = 2;

	cin >> N;
	for (int i = 0; i < N; i++)
		initPoint = (initPoint * 2) - 1;

	cout << initPoint * initPoint;
}