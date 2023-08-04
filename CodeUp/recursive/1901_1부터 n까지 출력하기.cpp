#include <iostream>

using namespace std;
int N;
void F(int num)
{
	if (num == N)
	{
		cout << N << '\n';
		return;
	}
	cout << num << '\n';
	F(num + 1);
}

int main()
{
	cin >> N;
	F(1);
}