#include <iostream>
#include <math.h>
using namespace std;

/*
1. ���� �Ʒ��� �ִ� ������ �� ������ �ű�� ���ؼ�
������ ���ǵ��� ��� �־�� �Ѵ�.

2. ���� �Ʒ��� �ִ� ������ �� ������ �ű��.

3. ��� �ִ� ������ ���ǵ��� �� ������ �ű��.

*/
//�ϳ���ž �̵� �ּ� Ƚ���� 2^n-1

/*
���� - ����
���� - ����
���� - ����

�������� ���
*/
//����, ����, ������, ������
void Hanoi(int num, char fromA, char midB, char toC)
{
	if (num == 1)
	{
		//A�� C�� �ű��.
		cout << fromA << " " << toC << '\n';
		return;
	}

	//n-1�� ~ 1���� A���� (C�� ����) B�� �ű��. 
	Hanoi(num - 1, fromA, toC, midB);

	cout << fromA << " " << toC << '\n';

	//n-1�� ~ 1���� A�κ��� �ű� B���� (A�� ����) C�� �ű��.
	Hanoi(num - 1, midB, fromA, toC);
}

int main()
{
	int N;
	cin >> N;
	cout << ((int)pow(2, N)) - 1 << '\n';
	Hanoi(N, '1', '2', '3');
}