#include <iostream>
using namespace std;

void F(int n)
{
	if (n / 2)
		F(n / 2);

	cout << n % 2;
}

int main()
{
	int N;
	cin >> N;
	F(N);
}