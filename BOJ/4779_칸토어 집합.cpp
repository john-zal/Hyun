#include <iostream>
#include <math.h>

using namespace std;

void Cantor(int n)
{
	int size = (int)pow(3, n - 1); //��� �ڸ� ũ��

	if (n == 0)
	{
		cout << '-';
		return;
	}

	//���� - �߰� - ��
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