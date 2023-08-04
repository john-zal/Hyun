#include <iostream>

using namespace std;
int N;

int F(int num)
{
	if (num <= 0)
		return 0;

	return num + F(num - 1);
}

int main()
{
	cin >> N;
	cout << F(N);
}