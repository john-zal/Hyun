#include <iostream>

using namespace std;

void F(int n)
{
	if (n == 1)
	{
		cout << 1 << '\n';
		return;
	}
		
	n % 2 ? F(3 * n + 1) : F(n / 2);
	cout << n << '\n';
}

int main()
{
	int N;
	cin >> N;
	F(N);
}