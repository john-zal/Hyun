#include <iostream>

using namespace std;

int main()
{
	//�� �ݾ�, ���� ����, ���� ����, ���� ����
	int X, N, a, b;
	cin >> X >> N;

	int sum = 0;

	while (N--)
	{
		cin >> a >> b;
		sum += a * b;
	}

	cout << (sum == X ? "Yes\n" : "No\n");

	return 0;
}