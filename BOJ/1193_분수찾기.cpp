#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	//Ȧ���϶�  ���� ���� �и� ���
	//¦���϶� ���� ��� �и� ����

	int line = 0;
	int i = 0;
	int length = 0;
	for (i = 1; ; i++)
	{
		line += i;
		if (line >= N)
			break;	
	}

	length = line - N + 1;

	int numA = length;
	int numB = i+1 - length;

	i % 2 ? cout << numA << "/" << numB 
			: cout << numB << "/" << numA;

}