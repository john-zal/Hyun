#include <iostream>

using namespace std;

int F(int n)
{
	if (n == 1)
		return 1;

	cout << n << '\n';
	return n % 2 ? F(3 * n + 1) : F(n / 2);
}

int main()
{
	int N;
	cin >> N;
	cout << F(N);
}