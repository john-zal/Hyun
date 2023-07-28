#include <iostream>
#include <math.h>

using namespace std;

void Cantor(int n)
{
	int size = (int)pow(3, n - 1); //가운데 자를 크기

	if (n == 0)
	{
		cout << '-';
		return;
	}

	//시작 - 중간 - 끝
	Cantor(n - 1);

	while (size--)
		cout << ' ';

	Cantor(n - 1);
}

int main()
{
	int N;
	while (cin >> N)
	{
		Cantor(N);
		cout << '\n' << endl;
	}
	return 0;
}