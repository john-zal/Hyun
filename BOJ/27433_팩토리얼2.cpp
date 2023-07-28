#include <iostream>

using namespace std;
using ll = long long;

ll Factorial(ll n)
{
	if (n == 0)
		return 1;

	return Factorial(n - 1) * n;
}

int main()
{
	ll num = 0;
	cin >> num;
	cout << Factorial(num) << endl;
	return 0;
}