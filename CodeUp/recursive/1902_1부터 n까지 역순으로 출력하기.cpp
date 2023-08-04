#include <iostream>

using namespace std;

int N;

void F(int num)
{
	if (num == 0)
		return;

	cout << num << '\n';
	F(num - 1);
}

int main()
{
	cin >> N;
	F(N);
}