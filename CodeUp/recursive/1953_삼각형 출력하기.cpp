#include <iostream>

using namespace std;

int N;

//�ٹٲ�
void F2(int n)
{
	if (!n) // 0�Ǹ� Ż��
	{
		cout << '\n';
		return;
	}

	cout << "*";
	F2(n - 1);
}
void F(int n)
{
	if (n > N)
		return;

	//n�� ��ŭ �� ��� 1.. 2.. 3.. 4.. 5..
	F2(n);
	F(n+1);
}

int main()
{
	cin >> N;
	F(1);
}