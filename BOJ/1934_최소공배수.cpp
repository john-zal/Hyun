#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	//a�� �� ū ��, b�� �� ���� ���� ��ġ�ߴ�.
	//a%b�� ������ ����� 0�� ���´ٸ� �� ���� �ּҰ�����̴�.
	/*
	ex) 6, 10 
	10 % 6  -> ������ �ߴ� 6�� left�� ������ �������� ���� 4�� right�� �д�.
	6 % 4	-> ������ �ߴ� 4�� left�� ������ �������� ���� 2�� right�� �д�.
	4 % 2	-> ������ �ߴ� 2�� left�� ������ �������� ���� 0�� right�� �д�.
	-> b(right)�� 0�� �Ǿ����Ƿ� ���� left�� 2�� ��ȯ�Ѵ�.

	(����a * ����b) / �ִ����� = �ּҰ�����̴�.
	*/
	return b ? gcd(b, a % b) : a;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	int a, b ,answer;
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		answer = (a * b) / gcd(max(a, b), min(a, b));
		cout << answer << '\n';	
	}
}