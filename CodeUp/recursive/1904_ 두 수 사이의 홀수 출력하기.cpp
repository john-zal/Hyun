#include <iostream>
using namespace std;

int N, M;

void F(int num)
{
	if (num == M)
	{
		M % 2 ? cout << M << '\n' : cout << '\n';
		return;
	}

	if (num % 2)
		cout << num << ' ';

	F(num + 1);
}

int main()
{
	cin >> N >> M;
	F(N);
}